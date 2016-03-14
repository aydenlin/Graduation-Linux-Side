#include "network.h"
#include "tools.h"
#include <netinet/in.h>
#include <sys/socket.h>
#include <string.h>
#include <malloc.h>

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

	network->connfd = 0;	
	network->network_listen = network_listen;
	network->network_accept = network_accept;
	network->read = read;
	network->write = write;
}

void network_listen(Network *network) {
	listen(network->listenfd, LISTEN_QUEUE_CAPACITY);
}

socket_descriptor network_accept() { 
		
}

byte * read() {

}

void write(byte *pb) {

}




