#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/socket.h>

#include <netinet/in.h>

#include <errno.h>
//for closing connection
#include <unistd.h>


int main() { 

	char server_message[256] = "You have reached the server \n";


	//create the server socket
	int server_socket = socket(AF_INET,SOCK_STREAM,0);

	// define the server address
	struct sockaddr_in server_address;
	server_address.sin_family = AF_INET;
	server_address.sin_port = htons(5132);
	server_address.sin_addr.s_addr = INADDR_ANY;


	// bind the socket to our specified address and port
	bind(server_socket,(const struct sockaddr*) &server_address,sizeof(server_address));

	// listen
	listen(server_socket, 5);


	//define socket that requested us
	int client_socket = accept(server_socket,NULL,NULL);

	//send message
	send(client_socket,server_message,sizeof(server_message),0);

	//close the socket
	close(server_socket);
	close(server_socket);




}