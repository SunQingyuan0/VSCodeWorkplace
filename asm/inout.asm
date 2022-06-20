
DATAS SEGMENT
    BUF1  DB 20H
          DB 0
          DB 20H DUP(0)
    CH1   DB 10 DUP(0)
    NUM1  DW 2 DUP(0)
    NUM2  DW 2 DUP(0)
    CH2   DW 20 DUP(0)
    CH3   DW 20 DUP(0)
DATAS ENDS



STACKS SEGMENT PARA STACK
           DW 100 DUP(0)
    BTM    DW ?
STACKS ENDS



CODES SEGMENT
            ASSUME CS:CODES,DS:DATAS,SS:STACKS
START:
            MOV    AX,DATAS
            MOV    DS,AX
            MOV    SP,OFFSET BTM
            MOV    AH,0AH
            LEA    DX,BUF1
            INT    21H
            LEA    DI,NUM1
            CALL   FAR PTR STOI
            INT    21H
            LEA    DI,NUM2
            CALL   FAR PTR STOI
            MOV    AX,0
            MOV    AH,4CH
            INT    21H


ADD32       PROC   FAR
;DX:AX + CX:BX,返回DX:AX
            ADD    AX,BX
            ADC    DX,CX
            RETF
ADD32 ENDP

SUB32       PROC FAR
;DX:AX - CX:BX,返回DX:AX
            SUB    AX,BX
            SBB    DX,CX
            RETF
SUB32 ENDP

SUB322       PROC FAR
;CX :BX - DX:AX,返回CX:BX
            SUB    BX,AX
            SBB    CX,DX
            RETF
SUB322 ENDP

MUL32       PROC   FAR
;DX:AX x CX:BX,返回DX:AX:CX:BX
            PUSH   SI
            PUSH   DI
            MOV    SI,DX                          ;存高位
            MOV    DI,AX                          ;存低位
            MUL    BX                             ;两个低位相乘
            PUSH   AX                             ;相继入栈
            PUSH   DX
            MOV    AX,SI                          ;高位DX赋给AX
            MUL    BX                             ;一个高位和一个低位相乘
            POP    BX                             ;第二个字出栈
            ADD    AX,BX                          ;更新第二字节的值
            ADC    DX,0
            PUSH   AX                             ;第二字节入栈
            MOV    BX,DX
            MOV    AX,DI                          ;低位字节赋值
            MUL    CX                             ;一个高位乘一个低位
            POP    DI                             ;修改第二字节
            ADD    DI,AX
            PUSH   DI
            MOV    DI,0
            ADC    BX,DX                          ;修改第三字节
            ADC    DI,0                           ;保存进位
            MOV    AX,SI                          ;
            MUL    CX                             ;两个高位相乘
            ADD    AX,BX                          ;修改第三字节
            ADC    DX,DI
            POP    CX                             ;第二字节出栈
            POP    BX                             ;第一字节出栈
            POP    DI
            POP    SI
            RETF
MUL32 ENDP

DIVDW PROC FAR ;DX为高16位，AX为低16位，CX是除数，返回：商（32位）DX:AX，余数：CX
	;先计算高位，再计算低位。低位先入栈
	  PUSH AX		; 先将低位数据入栈，因为后面的DIV需要占用AX寄存器
	  MOV AX,DX	; 将被除数（X的高16位）放入被除数的低16位AX中
	  MOV DX,0    ; 将被除数的高十六位DX清零
	  DIV CX	    ; INT(H/N), 存入AX(商)中,REM(H/N)存入DX(余数)中
	  MOV BX,AX   ; 临时保存AX
	  POP AX      ; 取出先前入栈的X的低位
	  DIV CX		; L\N
	  MOV CX,DX   ; 余数保存在CX里
	  MOV DX,BX   ; DX保存的是最终结果的高位
      RETF
DIVDW ENDP

STOI        PROC   FAR          ;   字符转数字
            PUSH   SI
            PUSH   AX
            PUSH   BX
            PUSH   CX
            PUSH   DX
            MOV    DX,0
            MOV    BX,10
            MOV    SI,2
            MOV    WORD PTR [DI],0
            MOV    WORD PTR [DI+2],0
            MOV    AX,0     ;初始化
LOP:
            MOV    AL,BUF1[SI];秦九韶算法
            CMP    AL,0DH;空格直接退出
            JE     FINAL
            SUB    AL,30H;ASCII码转换
            CMP    WORD PTR [DI],0  ;判断是否为0，与逻辑
            JNE    NEXT2
NEXT1:
            CMP    WORD PTR [DI+2],0
            JE     DO_DEAL
NEXT2:
            PUSH   AX
            MOV    AX,[DI]
            MOV    DX,[DI+2]
            MOV    CX,0
            CALL   FAR PTR MUL32  ;置寄存器，乘10
            MOV    [DI],BX
            MOV    [DI+2],CX
            POP    AX
DO_DEAL:
            ADD    [DI],AX  ;加下一位
            ADC    WORD PTR [DI+2],0
            MOV    AX,0
            INC    SI
            JMP    LOP
FINAL:
            POP DX
            POP CX
            POP BX
            POP AX
            POP SI
            RETF
STOI ENDP


DTOC:   PROC FAR;DX:AX，32位数据转字符，存到DI
        PUSH AX
		PUSH BX
		PUSH SI
        PUSH CX
		MOV BX,10
		MOV SI,0
S0:
		MOV DX,0
        MOV CX,10
		CALL FAR PTR DIVDW		;
		ADD CX,30H  ; 余数加30
		PUSH CX		; 入栈
        CMP AX,0
        JNE NEXT3
        CMP DX,0
        JE NEXT4
NEXT3:
		INC SI		; 记录循环次数
	    JMP S0  	;
NEXT4:
		MOV CX,SI	; CX 为循环次数
S1:
		POP DS:[DI]	; 将栈中转化好了的数据放到内存中
		INC SI
		LOOP S1
        MOV BYTE PTR [DI],0DH
        MOV BYTE PTR [DI+1],0AH
        MOV BYTE PTR [DI+2],'$'
        POP CX
		POP SI
		POP BX
		POP AX
		RETF
DTOC ENDP

SQRT    PROC FAR ;输入DX:AX,返回在SI
        PUSH BX
        PUSH CX
        MOV SI,0
        MOV   CX,0
        MOV   BX,1
_S_LOOP:
        CALL FAR PTR SUB32
        JC    _END            ;减，到有借位为止
        ADD   BX,2
        ADC   CX,0
        INC   SI             ;n加1
        JMP   _S_LOOP         ;反复的减
_END:
        POP   CX
        POP   BX
        RETF
SQRT ENDP
GETS    PROC FAR    ;传入DX:AX,返回在DI所指,求一个32位数的因子和
        PUSH BX
        PUSH CX
        PUSH SI
        CALL FAR PTR SQRT ;开方
        INC SI
        MOV  CX,1;设置计数
NEXT5:
        CMP SI,CX
        JC  NEXT8
        PUSH DX
        PUSH AX
        PUSH CX
        MOV BX,CX
        CALL FAR PTR DIVDW  ;大数取余
        CMP CX,0 ;是否整除
        JNZ NEXT7
        MOV CX,0
        CALL FAR PTR SUB322
        JNC NEXT6 ;除数不小于商
        ADD [DI],AX
        ADD [DI+2],DX
NEXT6:
        ADD [DI],BX
        ADC [DI+2],CX

NEXT7:
        POP CX
        POP AX
        POP DX
        JMP NEXT5
NEXT8:
        POP SI
        POP CX
        POP BX
        RETF
GETS    ENDP
CODES ENDS
    END START
