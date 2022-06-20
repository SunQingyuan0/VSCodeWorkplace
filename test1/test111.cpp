#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;
//code by Howie Luo 2018.03.29 


static char reserveWord[32][20] = {
	"if","then","else","while","do"
};

static char operatorOrDelimiter[100][100] = {
    "+", "-", "*", "/", "<", "<=", ">", ">=", "=", "==",
     "!=", ";", "(", ")"
 };

static  char IDentifierTbl[1000][50] = { "" }; //锟斤拷示锟斤拷锟斤拷 

int SearchReserve(char reserveWord[][20], char s[])
{
    for (int i = 0; i <32 ; i++)
   {
        if (strcmp(reserveWord[i], s) == 0)
        {//锟斤拷锟缴癸拷锟斤拷锟揭ｏ拷锟津返伙拷锟街憋拷锟斤拷
           return i + 1;//锟斤拷锟斤拷锟街憋拷锟斤�?
        }
   }   return -1;//锟斤拷锟津返伙拷-1锟斤拷锟斤拷锟斤拷锟斤拷锟揭诧拷锟缴癸拷锟斤拷锟斤拷为锟斤拷识锟斤拷
  
}

bool JudgeLetter(char letter)
{//注锟斤拷C锟斤拷锟斤拷锟斤拷锟斤拷锟铰伙拷锟斤拷也为锟斤拷识锟斤拷锟斤拷一锟斤拷锟街匡拷锟皆凤拷锟斤拷锟阶诧拷锟斤拷锟斤拷锟斤拷锟截凤�?
    if (letter >= 'a'&&letter <= 'z' || letter >= 'A'&&letter <= 'Z'|| letter=='_')
     {
        return true;
    }
    else
    {
        return false;
    }
 }

bool JudgeDigit(char digit)
{
     if (digit >= '0'&&digit <= '9')
    {
         return true;
     }
     else
     {
         return false;
     }
 }


void filterResource(char r[], int pProject)
 {
     char tempString[10000];
     int count = 0;
     for (int i = 0; i <= pProject; i++)
     {
         if (r[i] == '/'&&r[i + 1] == '/')
         {//锟斤拷为锟斤拷锟斤拷注锟酵★�?//锟斤�?,锟斤拷去锟斤拷注锟酵猴拷锟斤拷亩锟斤拷锟斤拷锟街憋拷锟斤拷锟斤拷锟斤拷爻锟斤拷锟斤拷锟�
             while (r[i] != '\n')
             {
                 i++;//锟斤拷锟缴�锟斤�?
             }
         }
         if (r[i] == '/'&&r[i + 1] == '*')
         {//锟斤拷为锟斤拷锟斤拷注锟酵★�?/* 锟斤拷锟斤拷锟斤�?*/锟斤拷锟斤拷去锟斤拷锟斤拷锟斤拷锟斤�?
             i += 2;
             while (r[i] != '*' || r[i + 1] != '/')
             {
                 i++;//锟斤拷锟斤拷扫锟斤拷
                 if (r[i] == '$')
                 {
                     printf("注锟酵筹拷锟斤拷锟斤拷没锟斤拷锟揭碉�? */锟斤拷锟斤拷锟斤拷锟斤拷锟斤拷锟斤拷锟斤拷锟絓n");
                     exit(0);
                 }
             }
             i += 2;//锟斤拷锟斤拷锟�*/锟斤�?
         }
         if (r[i] != '\n'&&r[i] != '\t'&&r[i] != '\v'&&r[i] != '\r')
         {//锟斤拷锟斤拷锟斤拷锟斤拷锟斤拷锟街凤拷锟斤拷锟斤拷锟斤拷耍锟斤拷锟斤拷锟斤拷锟斤�?
             tempString[count++] = r[i];
         }
     }
     tempString[count] = '\0';
     strcpy(r, tempString);//锟斤拷锟斤拷锟斤拷锟斤拷之锟斤拷锟皆达拷锟斤拷锟�?
}
//锟斤拷锟斤拷DFA锟斤拷状态转锟斤拷图锟斤拷锟�?
void Scanner(int &syn, char resourceProject[], char token[], int &pProject)
{
     int i, count = 0;//count锟斤拷锟斤拷锟斤拷token[]锟斤拷指示锟斤拷锟斤拷锟秸硷拷锟斤拷锟斤拷锟街凤�?
     char ch;//锟斤拷为锟叫讹拷使锟斤拷
     ch = resourceProject[pProject];
     while (ch == ' ')
     {//锟斤拷锟剿空格，凤拷止锟斤拷锟斤拷锟斤拷识锟斤拷锟剿空革拷锟斤拷锟斤拷锟�?
         pProject++;
         ch = resourceProject[pProject];
     }
     for (i = 0; i<20; i++)
    {//每锟斤拷锟秸硷拷前锟斤拷锟斤拷锟斤拷
        token[i] = '\0';
    }
    if (JudgeLetter(resourceProject[pProject]))
     {//锟斤拷头为锟斤拷�?
         token[count++] = resourceProject[pProject];//锟秸硷拷
      pProject++;//锟斤拷锟斤拷
       while (JudgeLetter(resourceProject[pProject]) || JudgeDigit(resourceProject[pProject]))
         {//锟斤拷锟斤拷锟侥革拷锟斤拷锟斤拷锟�
             token[count++] = resourceProject[pProject];//锟秸硷拷
             pProject++;//锟斤拷锟斤拷
         }//锟斤拷锟斤拷锟揭伙拷锟斤拷址锟斤拷锟斤拷锟斤拷麓谓锟揭�锟斤拷始锟斤拷指锟斤拷位锟斤�?
         token[count] = '\0';
         syn = SearchReserve(reserveWord, token);//锟斤拷锟斤拷业锟斤拷直锟斤拷锟�
         if (syn == -1)
         {//锟斤拷锟斤拷锟角憋拷锟斤拷锟斤拷锟斤拷锟角憋拷识锟斤�?
             syn = 100;//锟斤拷识锟斤拷锟街憋拷锟斤拷
         }
         return;
     }
     else if (JudgeDigit(resourceProject[pProject]))
     {//锟斤拷锟街凤拷为锟斤拷锟斤拷
         while (JudgeDigit(resourceProject[pProject]))
         {//锟斤拷锟斤拷锟斤拷锟�?
             token[count++] = resourceProject[pProject];//锟秸硷拷
             pProject++;
         }//锟斤拷锟斤拷锟揭伙拷锟斤拷址锟斤拷锟斤拷锟斤拷麓谓锟揭�锟斤拷始锟斤拷指锟斤拷位锟斤�?
         token[count] = '\0';
         syn = 99;//锟斤拷锟斤拷锟街憋拷锟斤�?
     }
     else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == ';' || ch == '(' || ch == ')' || ch == '^'
         || ch == ',' || ch == '\"' || ch == '\'' || ch == '~' || ch == '#' || ch == '%' || ch == '['
         || ch == ']' || ch == '{' || ch == '}' || ch == '\\' || ch == '.' || ch == '\?' || ch == ':')
     {//锟斤拷为锟斤拷锟斤拷锟斤拷锟斤拷呓锟斤拷锟斤拷锟斤拷锟斤拷玫锟斤拷锟斤拷
         token[0] = resourceProject[pProject];
         token[1] = '\0';//锟轿成碉拷锟街凤拷锟斤拷
         for (i = 0; i<36; i++)
         {//锟斤拷锟斤拷锟斤拷锟斤拷锟斤拷锟斤拷
             if (strcmp(token, operatorOrDelimiter[i]) == 0)
             {
                 syn = 33 + i;//锟斤拷锟斤拷直锟斤拷耄�使锟斤拷锟斤拷一锟姐技锟缴ｏ拷使之锟斤拷锟斤拷锟斤拷映锟斤�?
                 break;//锟介到锟斤拷锟狡筹拷
             }
         }
         pProject++;//指锟斤拷锟斤拷锟狡ｏ拷为锟斤拷一扫锟斤拷锟斤拷准锟斤�?
         return;
     }
     else  if (resourceProject[pProject] == '<')
     {//<,<=,<<
         pProject++;//锟斤拷锟狡ｏ拷锟斤拷前锟斤拷锟斤�?
         if (resourceProject[pProject] == '=')
         {
             syn = 38;
         }
         else if (resourceProject[pProject] == '<')
         {//锟斤拷锟斤拷
             pProject--;
             syn = 58;
         }
         else
         {
             pProject--;
             syn = 37;
         }
         pProject++;//指锟斤拷锟斤拷锟斤拷
         return;
     }
     else  if (resourceProject[pProject] == '>')
     {//>,>=,>>
        pProject++;
         if (resourceProject[pProject] == '=')
         {
             syn = 40;
         }
         else if (resourceProject[pProject] == '>')
         {
             syn = 59;
         }
         else
         {
             pProject--;
             syn = 39;
         }
         pProject++;
         return;
     }
     else  if (resourceProject[pProject] == '=')
     {//=.==
         pProject++;
         if (resourceProject[pProject] == '=')
         {
             syn = 42;
         }
         else
         {
             pProject--;
             syn = 41;
         }
         pProject++;
         return;
     }
     else  if (resourceProject[pProject] == '!')
     {//!,!=
         pProject++;
         if (resourceProject[pProject] == '=')
         {
             syn = 43;
         }
         else
         {
             syn = 68;
             pProject--;
         }
         pProject++;
         return;
     }
     else  if (resourceProject[pProject] == '&')
     {//&,&&
         pProject++;
         if (resourceProject[pProject] == '&')
         {
             syn = 53;
         }
         else
         {
             pProject--;
             syn = 52;
         }
         pProject++;
         return;
     }
     else  if (resourceProject[pProject] == '|')
     {//|,||
         pProject++;
         if (resourceProject[pProject] == '|')
         {
             syn = 55;
         }
         else
         {
             pProject--;
             syn = 54;
         }
         pProject++;
         return;
     }
     else  if (resourceProject[pProject] == '$')
     {//锟斤拷锟斤拷锟斤�?
         syn = 0;//锟街憋拷锟斤拷为0
     }
     else
     {//锟斤拷锟杰憋拷锟斤拷锟较词凤拷锟斤拷锟斤拷识锟斤拷锟斤拷锟斤拷锟斤拷锟�
         printf("error锟斤拷there is no exist %c \n", ch);
         exit(0);
     }
 };
 
 
 int main()
 {
     //锟斤拷一锟斤拷锟侥硷拷锟斤拷锟斤拷取锟斤拷锟叫碉拷源锟斤拷锟斤拷
     char resourceProject[10000];
     char token[20] = { 0 };
     int syn = -1, i;//锟斤拷始锟斤�?
     int pProject = 0;//源锟斤拷锟斤拷指锟斤�?
     FILE *fp, *fp1;
     if ((fp = fopen("D:\\vsc\\test1\\mytest.txt", "r")) == NULL)
     {//锟斤拷源锟斤拷锟斤拷
         cout << "can't open this file";
         exit(0);
     }
     resourceProject[pProject] = fgetc(fp);
     while (resourceProject[pProject] != '$')
     {//锟斤拷源锟斤拷锟斤拷锟斤拷锟絩esourceProject[]锟斤拷锟斤拷
         pProject++;
         resourceProject[pProject] = fgetc(fp);
     }
     resourceProject[++pProject] = '\0';
     fclose(fp);
     cout << endl << "源锟斤拷锟斤拷为:" << endl;
    cout << resourceProject << endl;
     //锟斤拷源锟斤拷锟斤拷锟斤拷泄锟斤拷锟�?
     filterResource(resourceProject, pProject);
     cout << endl << "锟斤拷锟斤拷之锟斤拷某锟斤拷锟�:" << endl;
     cout << resourceProject << endl;
     pProject = 0;//锟斤拷头锟斤拷始锟斤�?
 
     if ((fp1 = fopen("D:\\锟绞凤拷锟斤拷锟斤拷锟斤拷锟斤拷锟缴的筹拷锟斤拷路锟斤拷", "w+")) == NULL)
     {//锟斤拷源锟斤拷锟斤拷
         cout << "can't open this file";
         exit(0);
     }
     while (syn != 0)
     {
         //锟斤拷锟斤拷扫锟斤拷
         Scanner(syn, resourceProject, token, pProject);
         if (syn == 100)
         {//锟斤拷识锟斤�?
             for (i = 0; i<1000; i++)
             {//锟斤拷锟斤拷锟绞讹拷锟斤拷锟斤拷锟�
                 if (strcmp(IDentifierTbl[i], token) == 0)
                 {//锟斤拷锟节憋拷锟斤拷
                     break;
                 }
                 if (strcmp(IDentifierTbl[i], "") == 0)
                 {//锟斤拷锟揭空硷拷
                     strcpy(IDentifierTbl[i], token);
                     break;
                 }
             }
             printf("(锟斤拷识锟斤�?  ,%s)\n", token);
             fprintf(fp1, "(锟斤拷识锟斤�?   ,%s)\n", token);
         }
         else if (syn >= 1 && syn <= 32)
         {//锟斤拷锟斤拷锟斤�?
             printf("(%s   ,  --)\n", reserveWord[syn - 1]);
             fprintf(fp1, "(%s   ,  --)\n", reserveWord[syn - 1]);
         }
         else if (syn == 99)
         {//const 锟斤拷锟斤拷
             printf("(锟斤拷锟斤拷   ,   %s)\n", token);
             fprintf(fp1, "(锟斤拷锟斤拷   ,   %s)\n", token);
         }
         else if (syn >= 33 && syn <= 68)
         {
             printf("(%s   ,   --)\n", operatorOrDelimiter[syn - 33]);
             fprintf(fp1, "(%s   ,   --)\n", operatorOrDelimiter[syn - 33]);
         }
     }
     for (i = 0; i<100; i++)
     {//锟斤拷锟斤拷锟绞讹拷锟斤拷锟斤拷锟�
         printf("锟斤�?%d锟斤拷锟斤拷识锟斤拷锟斤�?  %s\n", i + 1, IDentifierTbl[i]);
         fprintf(fp1, "锟斤�?%d锟斤拷锟斤拷识锟斤拷锟斤�?  %s\n", i + 1, IDentifierTbl[i]);
     }
     fclose(fp1);
     return 0;
};

