#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <winsock2.h>
#pragma comment (lib, "ws2_32.lib")

#define MAKEWORD(a, b) ((WORD)(((BYTE)(((DWORD_PTR)(a)) & 0xff)) | ((WORD)((BYTE)(((DWORD_PTR)(b)) & 0xff))) << 8))

/*
*   连接服务器
*/
SOCKET connect_server(char *host, int port);
/*
*   断开服务器
*/
void disconnect(SOCKET c);

void send_msg(SOCKET c, char *msg);
void recv_msg(SOCKET c);
char *base64_encode(char *str);

SOCKET connect_server(char *host, int port)
{
    WSADATA wd;
    int ret = 0;
    SOCKET c;
    SOCKADDR_IN saddr;
    struct hostent *pHostent;

    ret = WSAStartup(MAKEWORD(2,2), &wd);

    if(ret != 0)
    {
        return 0;
    }

    if(HIBYTE(wd.wVersion)!=2 || LOBYTE(wd.wVersion)!=2)
    {
        printf("init erro");
        WSACleanup();
        return 1;
    }

    c = socket(AF_INET, SOCK_STREAM, 0);

    pHostent = gethostbyname(host);

    saddr.sin_addr.S_un.S_addr = *((unsigned long*)pHostent->h_addr_list[0]);
    saddr.sin_family = AF_INET;
    saddr.sin_port = htons(port);

    connect(c, (SOCKADDR*)&saddr, sizeof(SOCKADDR));

    return c;
}

void disconnect(SOCKET c)
{
    closesocket(c);
    WSACleanup();
}

void recv_msg(SOCKET c)
{
    char text[BUFSIZ];
    //strnset(text, '\0', BUFSIZ);
    recv(c, text, BUFSIZ, 0);
    printf("recv:%s\n", text);
}

void send_msg(SOCKET c, char *msg)
{
    printf("send:%s\n", msg);
    send(c, msg, strlen(msg), 0);
}

char *base64_encode(char *str)
{
    long len;
    long str_len;
    char *res;
    int i,j;
    //定义base64编码表
    char *base64_table="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

    //计算经过base64编码后的字符串长度
    str_len=strlen(str);
    if(str_len % 3 == 0)
        len=str_len/3*4;
    else
        len=(str_len/3+1)*4;

    res=(char*)malloc(sizeof(char)*len+1);
    res[len]='\0';

    //以3个8位字符为一组进行编码
    for(i=0,j=0;i<len-2;j+=3,i+=4)
    {
        res[i]=base64_table[str[j]>>2];                             //取出第一个字符的前6位并找出对应的结果字符
        res[i+1]=base64_table[(str[j]&0x3)<<4 | (str[j+1]>>4)];     //将第一个字符的后位与第二个字符的前4位进行组合并找到对应的结果字符
        res[i+2]=base64_table[(str[j+1]&0xf)<<2 | (str[j+2]>>6)];   //将第二个字符的后4位与第三个字符的前2位组合并找出对应的结果字符
        res[i+3]=base64_table[str[j+2]&0x3f];                       //取出第三个字符的后6位并找出结果字符
    }

    switch(str_len % 3)
    {
        case 1:
            res[i-2]='=';
            res[i-1]='=';
            break;
        case 2:
            res[i-1]='=';
            break;
    }

    return res;
}


int main()
{
    char sendbuf[BUFSIZ];
    char *ptr = NULL;
    char *host = "smtp.163.com";
    int port = 25;
    SOCKET c;

    c = connect_server(host, port);
    recv_msg(c);

    send_msg(c, "helo 163\n");
    recv_msg(c);

    send_msg(c, "auth login\n");
    recv_msg(c);

    ptr = base64_encode("wei18280005519@163.com");
    strcpy(sendbuf, ptr);
    strcat(sendbuf, "\n");
    send_msg(c, sendbuf);
    recv_msg(c);

    ptr = base64_encode("627weipeng");
    strcpy(sendbuf, ptr);
    strcat(sendbuf, "\n");
    send_msg(c, sendbuf);
    recv_msg(c);

    strcpy(sendbuf, "mail from:<wei18280005519@163.com>\n");
    send_msg(c, sendbuf);
    recv_msg(c);
    strcpy(sendbuf, "rcpt to:<18983362864@163.com>\n");
    send_msg(c, sendbuf);
    recv_msg(c);

	send_msg(c, "data\n");
	recv_msg(c);
	strcpy(sendbuf, "from:<wei18280005519@163.com>\nto:<18983362864@163.com>\n");
    send_msg(c, sendbuf);
    strcpy(sendbuf, "subject:hello\n\n");
    strcat(sendbuf, "Hello world!\n");
    strcat(sendbuf, ".\n");
    send_msg(c, sendbuf);
    recv_msg(c);

    disconnect(c);
    printf("邮件已发送!\n");
    printf("Hello world!\n");
    return 0;
}
