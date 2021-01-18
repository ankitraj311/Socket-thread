//Flow :- Socket_creation-> Connection_Details-> Binding/Connecting-> Listening-> Accepting-> Sending-> Closing
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>



int main()
{
        /////////////////////////////////////////////////////////////////Defining String to be Send//////////////////////
	char server_message[256] = "You have been reached the Server";


	//creating the socket with socket function/////////////////////////Socket Creation/////////////////////////////////	
	int server_socket;
	server_socket = socket(AF_INET, SOCK_STREAM, 0);


	//Defining Server connecting details//////////////////////////////Defining Connection Details///////////////////////
	struct sockaddr_in server_address;
	server_address.sin_family = AF_INET;
	server_address.sin_port = htons(9000);
	server_address.sin_addr.s_addr = INADDR_ANY;


	//Binding the socket to the specific socket like connect////////////Binding Details/////////////////////////////////
	bind(server_socket, (struct sockaddr*)&server_address, sizeof(server_address));


	//Listen at particular port and Ip/////////////////////////////////Listning on Port/////////////////////////////////
	listen(server_socket, 5); //5 is the backlog or queue, the number of connection can be the queue


	//Create an integer to hold the client socket////////////////////Socket Accepting Connection////////////////////////
	int client_socket;
	client_socket = accept(server_socket, NULL, NULL);
        //printf("Client socket is %d",client_socket); //receiving 9 value

	//send//////////////////////////////////////////////////////////Sending Data To Client Socket//////////////////////
	send(client_socket, server_message, sizeof(server_message),0);

	////////////////////////////////////////////////////////////////Closing Socket/////////////////////////////////////
	close(server_socket);
	return 0;
}

/*
 Commands to know about process id etc
 ps -efa | grep a.out            = process_id
 a.out &                         = process_id
 netstat -natp | grep process_id = listening port
 */



