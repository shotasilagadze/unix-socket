#include <stdio.h>
#include <stdlib.h>

#include <string.h>


#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>

#include <errno.h>
//for closing connection
#include <unistd.h>

int main() {

	//open the file to send to the client
	FILE * html_data;
	html_data = fopen("index.html","r");


	char response_data[1024];
	fgets(response_data,sizeof(response_data),html_data);

	char http_header[2048] = "HTTP/1.1 200 OK\r\n\n";
	strcat((char *)http_header,(const char *)response_data);


	//create server socket
	int server_socket = socket(AF_INET,SOCK_STREAM,0);

	//define the address
	struct sockaddr_in server_address;
	server_address.sin_family = AF_INET;
	server_address.sin_port = htons(5133);
	server_address.sin_addr.s_addr = INADDR_ANY;


	//bind the socket to particular inner address
	int bind_status = bind(server_socket,(struct sockaddr *) &server_address,sizeof(server_address));
	if (bind_status != 0) {
		printf("%s\n", "Bind error occured - ");
		printf("%d\n",errno);
	}


	//listen for incoming requests for the server
	listen(server_socket,5);


	//define the client socket we will accept
	int client_socket;

	char received_message[2000];

	while (1) {
		client_socket = accept(server_socket,NULL,NULL);
		recv(client_socket,received_message,2000,0);
		printf("%s\n",received_message);
	}
















	return 0;
}