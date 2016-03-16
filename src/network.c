#include "network.h"
#include "tools.h"
#include "types.h"
#include "datastruct.h"
#include <netinet/in.h>
#include <sys/socket.h>
#include <string.h>
#include <malloc.h>
#include <errno.h>

extern int errno;

/* 
 * NOTE: The parameter network should has been allocate
 * with enough memory.
 */
void network_initialize(Network *network, int port) {
	int *listenfd = &(network->listenfd);
	struct sockaddr_in *serveraddr = network->serveraddr =
		(struct sockaddr_in *)malloc(sizeof(struct sockaddr_in));


	*listenfd = socket(AF_INET, SOCK_STREAM, 0);
	bzero(serveraddr, sizeof(struct sockaddr_in));
	serveraddr->sin_family = AF_INET;
	serveraddr->sin_port = htons(port);
	serveraddr->sin_addr.s_addr = htonl(INADDR_ANY);

	bind(*listenfd, (SA *)serveraddr, sizeof(struct sockaddr_in));
	
	network->list_head = NULL;
	network->connfd = 0;	
	network->network_listen = network_listen;
	network->network_accept = network_accept;
	network->read = read;
	network->write = write;
}

void network_listen(Network *network) {
	listen(network->listenfd, LISTEN_QUEUE_CAPACITY);
}

void network_accept(Network *network) { 
	network->connfd = accept(network->listenfd, NULL, NULL);
}

int read_from(Network *network) {
	int nbytes;
	socket_descriptor socket = network->connfd;
	byte *recv = (byte *)malloc(_MAX_LENGTH_OF_PACKET_);
	List *element = (List *)malloc(sizeof(List));

	while ((nbytes = read(socket, recv, _MAX_LENGTH_OF_PACKET_)) > 0) {
		if (nbytes == 0)
			break;
		if (nbytes < 0) {
			errno = 1;
			exit(1);
		}
		INIT_LIST_ELEMENTS(element, recv);
		list_insert(network->list_head, element);
	}

}

void write_to(Network *network, byte *packet, int nbytes) {
	write(network->socket, packet, nbytes);
}




