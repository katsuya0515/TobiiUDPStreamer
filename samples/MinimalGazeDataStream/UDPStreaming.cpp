#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include "UDPStreaming.h"
WSAData wsaData;
SOCKET sock;
struct sockaddr_in addr;

void UDPStreaming_init(char* ip, int port){
	WSAStartup(MAKEWORD(2,0), &wsaData);

	sock = socket(AF_INET, SOCK_DGRAM, 0);

	addr.sin_family = AF_INET;
	addr.sin_port = htons(port);
	addr.sin_addr.S_un.S_addr = inet_addr(ip);
}

int UDPStreaming_send(unsigned char* buf, int len){
	return sendto(sock, (char *)buf, len,0,(struct sockaddr *)&addr, sizeof(addr));
}

void UDPStreaming_close(void){
	closesocket(sock);
	WSACleanup();
}