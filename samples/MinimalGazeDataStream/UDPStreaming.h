#include <winsock2.h>

void UDPStreaming_init(char* ip, int port);
int UDPStreaming_send(unsigned char* buf, int len);

void UDPStreaming_close(void);