#ifndef _NETWORK_H_
#define _NETWORK_H_

#include "datastruct.h"

#define _LISTEN_QUEUE_CAPACITY_ 100
#define SA struct sockaddr

typedef int socket_descriptor;

typedef Network_init(Network *network, int port);
typedef Network_listen(Network *network);
typedef void Network_accept(Network *network);
typedef int Network_read_from(Network *network);
typedef void Network_write_to(Network *network, byte *packet,
		int nbytes);
typedef void Network_obtain(Network *network);

typedef struct {
	int listenfd;
	int connfd;
	struct sockaddr_in *serveraddr;
	List_head *list_head;
	Network_init init;
	Network_listen listen;
	Network_accept accept;
	Network_read_from read_from;
	Network_write_to write_to;
	Network_obtain obtain;
} Network;

void network_initialize(Network *network, int port);
void network_listen(Network *network);
void network_accept();
int  network_read_from(Network *network);
void network_write_to(Network *network, byte *packet, int nbytes);
void network_obtain(Network *network);

#endif /* _NETWORK_H_ */
