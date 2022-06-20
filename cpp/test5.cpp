#include <stdio.h>
#include <string.h>
#include <Windows.h>
#define PASSWORD "123456"
int verify_password(char *password)
{
    int authenticated;
    char buffer[44];
    authenticated = strcmp(password, PASSWORD);
    strcpy(buffer, password);
    return authenticated;
}
int main()
{
    int valid_flag = 0;
    char password[1024];
    FILE *fp;
    LoadLibrary("user32.dll");
    if (!(fp = fopen("E:\\VSCodeWorkPlace\\cpp\\password.txt", "rw+")))
    {
        exit(0);
    }
    fscanf(fp, "%s", password);
    valid_flag = verify_password(password);
    if (valid_flag)
    {
        printf("incorrect password\n\n0");
    }
    else
    {
        printf("Congralation! You have passed the verification!\n");
    }
    fclose(fp);
    getchar();
    getchar();
    return 0;
}