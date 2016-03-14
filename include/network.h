#ifndef _NETWORK_H_
#define _NETWORK_H_

#define LISTEN_QUEUE_CAPACITY 100
#define SA struct sockaddr
#define NETWORK_INIT(net_obj, port) do { \
	network_initialize(net_obj, port); \
} while(0)

typedef int socket_descriptor;
typedef char byte;
typedef struct {
	int listenfd;
	int connfd;
	struct sockaddr_in *serveraddr;
	void (*network_listen)();
	socket_descriptor (*network_accept)();
	byte * (*read)();
	void (*write)(byte *pb);
} Network;

void network_initialize(Network *network, int port);
void network_listen(Network *network);
socket_descriptor network_accept();
byte *read();
void write();

#endif /* _NETWORK_H_ */
