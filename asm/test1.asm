DATAS SEGMENT
    BUF1  DB 20H
          DB 0
          DB 20H DUP(0)
    NUM   DW 2 DUP(0)
    NUM2  DW 2 DUP(0)

DATAS ENDS


STACKS SEGMENT PARA STACK
           DW 1000 DUP(0)
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
            LEA    DI,NUM
            CALL   STOI
            LEA    DI,NUM2
            CALL   STOI
            MOV    AX,0
            MOV    AH,4CH
            INT    21H
MUL32       PROC   NEAR
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
            RET
MUL32 ENDP
STOI        PROC   NEAR           ;   字符转数字
            PUSH   SI
            PUSH   AX
            PUSH   BX
            PUSH   CX
            PUSH   DX
            MOV    DX,0
            MOV    BX,10
            MOV    SI,2
            MOV    DI,0
            MOV    DI[2],0
            MOV    AX,0     ;初始化
LOP:
            MOV    AL,BUF1[SI];秦九韶算法
            CMP    AL,0DH;空格直接退出
            JE     FINAL
            SUB    AL,30H;ASCII码转换
            CMP    DI,0  ;判断是否为0，与逻辑
            JNE    NEXT2
NEXT1:
            CMP    DI[2],0
            JE     DO_DEAL
NEXT2:
            PUSH   AX
            MOV    AX,DI
            MOV    DX,DI[2]
            MOV    CX,0
            CALL   MUL32  ;置寄存器，乘10
            MOV    DI,BX
            MOV    DI[2],CX
            POP    AX
DO_DEAL:
            ADD    DI,AX  //加下一位
            ADC    DI[2],0
            MOV    AX,0
            INC    SI
            JMP    LOP
FINAL:
            POP DX
            POP CX
            POP BX
            POP AX
            POP SI
            RET
STOI ENDP
CODES ENDS
    END START