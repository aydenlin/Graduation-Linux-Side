#ifndef _NETWORK_H_
#define _NETWORK_H_

#include "datastruct.h"

#define _LISTEN_QUEUE_CAPACITY_ 100
#define SA struct sockaddr

typedef int socket_descriptor;
typedef struct network Network;

typedef void Network_init(Network *network, int port);
typedef void Network_listen(Network *network);
typedef void Network_accept(Network *network);
typedef int Network_read_from(Network *network);
typedef void Network_write_to(Network *network, byte *packet,
		int nbytes);
typedef byte * Network_obtain(Network *network);
typedef void Network_send(Network *network, byte *packet);
typedef int Is_work_here(Network *network);
typedef int Network_is_alive(Network *network);
typedef void Network_alive(Network *network);
typedef void Network_dead(Network *network);

int network_is_alive(Network *network);
void network_initialize(Network *network, int port);
void network_listen(Network *network);
void network_accept(Network *network);
int  network_read_from(Network *network);
void network_write_to(Network *network, byte *packet, int nbytes);
byte * network_obtain(Network *network);
void network_send(Network *network, byte *packet);
int is_work_here(Network *network); 
void network_alive(Network *network);
void network_dead(Network *network);

typedef struct network {
	int listenfd;
	int connfd;
	int alive;
	struct sockaddr_in *serveraddr;
	List_head *list_head;
	Network_init *init;
	Network_listen *listen;
	Network_accept *accept;
	Network_read_from *read_from;
	Network_write_to *write_to;
	Network_obtain *obtain;
	Network_send *send;
	Network_alive *set_alive;
	Network_dead *set_dead;
	Network_is_alive *is_alive;
	Is_work_here *is_work_here;
} Network;

#endif /* _NETWORK_H_ */
