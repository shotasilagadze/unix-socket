#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/socket.h>

#include <netinet/in.h>

#include <errno.h>
//for closing connection
#include <unistd.h>

//for converting string ip to binary 
#include <arpa/inet.h>

int main() {

   //create a socket
   int netword_socket;
   netword_socket = socket(AF_INET,SOCK_STREAM,0);

   //specify the address of the socket
   struct sockaddr_in server_address;
   server_address.sin_family = AF_INET;
   server_address.sin_port = htons(5132);
   inet_pton(AF_INET, "188.226.153.108", &server_address.sin_addr);
   


   //connect 
   int connection_status = connect(netword_socket,(const struct sockaddr *) &server_address,sizeof(server_address));
  

   //check for error with connection 
   if (connection_status == -1) {      
      printf("%s","connection error status - ");
      printf("%d\n",errno);
      return 0;   
   }   


   //receiving data from server
   char server_response[256];
   recv(netword_socket,&server_response,sizeof(server_response),0);

   //print the received data
   printf("server response: %s",server_response);


   //close socket
   close(netword_socket);


   return 0;
}