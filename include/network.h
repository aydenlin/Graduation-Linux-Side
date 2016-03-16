#ifndef _NETWORK_H_
#define _NETWORK_H_

#define _LISTEN_QUEUE_CAPACITY_ 100
#define SA struct sockaddr
#define _NETWORK_INIT_(net_obj, port) do { \
	network_initialize(net_obj, port); \
} while(0)

typedef int socket_descriptor;
typedef char byte;                     
typedef struct {
	int listenfd;
	int connfd;
	struct sockaddr_in *serveraddr;
	List_head *list_head;
	void (*network_listen)();
	socket_descriptor (*network_accept)();
	byte * (*read)();
	void (*write)(byte *pb);
} Network;

void network_initialize(Network *network, int port);
void network_listen(Network *network);
void network_accept();
int read_from(Network *network);
void write_to(Network *network, byte *packet, int nbytes);

#endif /* _NETWORK_H_ */
