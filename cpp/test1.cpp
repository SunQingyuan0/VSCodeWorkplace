#include<stdio.h>
#include<string.h>
#define PASSWORD "123456"
int verify_password(char *password)
{
    int authenticated;
    authenticated=strcmp(password,PASSWORD);
    return authenticated;
}
int main()
{
    int valid_flag=0;
    char password[1024];
    while (1)
    {
        printf("Please input password:   ");
        scanf("%s",password);
        valid_flag=verify_password(password);
        if(valid_flag)
        {
            printf("incorrect password\n\n0");
        }
        else
        {
            printf("Congralation! You have passed the verification!\n");
            break;
        }
    }
    getchar();
    getchar();
    return 0;
    
}