#include <ctime>
#include <winsock2.h>
#include <cstdio>
#pragma comment(lib, "ws2_32.lib")
#pragma warning(disable : 4996)
#define MAX_BUF 1024
#define SPORT 12345
#define SERVER_IP "127.0.0.1"
int all_num = 1024; // 设置客户端总的发包次数
/*套接字初始化*/
int win_init()
{
    WORD w_version = MAKEWORD(2, 2);
    WSADATA wsa_data;
    int res = WSAStartup(w_version, &wsa_data);
    if (res != 0)
    {
        printf("WSAStartup Error:%d\n", WSAGetLastError());
        return -1;
    } //版本号错误
    if (LOBYTE(wsa_data.wVersion) != 2 || HIBYTE(wsa_data.wVersion) != 2)
    {
        printf("WSAStartup Error:%d\n", WSAGetLastError());
        WSACleanup();
        return -1;
    }

    return 0; //成功返回0
}
/*释放资源*/
int win_end()
{
    int err = WSACleanup();
    if (err == SOCKET_ERROR)
    {
        printf("WSACleanup Error:%d", WSAGetLastError());
        return -1;
    }
    return 0;
}
/*断开连接，释放资源*/
int close_conn(SOCKET conn)
{
    int err = closesocket(conn); //关闭连接
    if (err == SOCKET_ERROR)
    {
        printf("关闭连接失败%d\n", WSAGetLastError());
        return -1;
    }
    err = win_end();
    return err;
}
/*客户端连接初始化*/
SOCKET init(sockaddr_in& server_addr)
{
    int sock_err = -1;
    SOCKET conn;
    // 设置地址、端口
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.S_un.S_addr = inet_addr(SERVER_IP);
    server_addr.sin_port = htons(SPORT);
    //创建套接字
    conn = socket(AF_INET, SOCK_DGRAM, 0);
    // 创建失败
    if (conn == INVALID_SOCKET)
    {
        printf("socket error:%d\n", WSAGetLastError());
        win_end();
        return -1;
    }
        // 请求连接服务器
        sock_err = connect(conn, (struct sockaddr*)&server_addr, sizeof(server_addr));
        // 连接 服务器失败
        if (sock_err == SOCKET_ERROR)
        {
            printf("connect error:%d\n", WSAGetLastError());
            close_conn(conn);
            return -1;
        }
    return conn; //连接成功
}
/*数据包发送函数*/
int client_control(int num, SOCKET conn, SOCKADDR* server_addr, int addr_len)
{
    int sock_err, i = 0;
    char send_buff[MAX_BUF];
    memset(send_buff, 0, sizeof(send_buff));
    memset(send_buff, 1, 100);
    for (i = 0; i < num; i++)
    {
        sock_err = sendto(conn, send_buff, (int)strlen(send_buff), 0, (SOCKADDR*)server_addr, addr_len);

        if (sock_err == SOCKET_ERROR)
        {
            printf("send error");
            return -1;
        }
    }
    return sock_err;
}
int main()
{
    win_init();
    int sock_err;
    SOCKET conn;
    char server_ip[] = "127.0,0,1";
    struct sockaddr_in server_addr;                   // 启动
    conn = init(server_addr); //连接
    printf("connection successfully\n");
    printf("num：");
    scanf("%d", &all_num);
    sock_err = client_control(all_num, conn, (SOCKADDR*)&server_addr, sizeof(sockaddr_in));
    close_conn(conn);
    return 0;
}
