//Flow :- Socket_creation-> Connection_Detail-> Connecting-> Receiving_Data-> Closing.
#include<stdio.h> //standard input output file
#include<stdlib.h> //malloc
#include<unistd.h> //close 
#include<sys/types.h> //structures needed
#include<sys/socket.h> //socket Calls
#include<netinet/in.h> //Internet type header file




int main()
{
      ///////////////////////////////////////////////////////String for receiving Data from  Server//////////////////////////////
      char server_response[256];

      ///////////////////////////////////////////////////////Creating Socket for Client/////////////////////////////////////////	
      int network_socket;
      network_socket = socket(AF_INET,SOCK_STREAM,0); //AF_INET is Domain of socket, SOCK_STREAM type of Socket, 0 for default tcp
                                                      //printf("network_socket value is %d\n",network_socket); //having value 3
  
  
      ////////////////////////////////////////////////////Detail of connection/////////////////////////////////////////////////
      struct sockaddr_in server_address;
      server_address.sin_family = AF_INET;         //Family domain
      server_address.sin_port = htons(9000);       //"HOST TO NETWORK SHORTS" port with which we want to connect.  htons convering port to appropiate data formate
      server_address.sin_addr.s_addr = INADDR_ANY; //this will used only when you want connect from all active ports you don't care about ip-add 
                                                   //connect to any 0.0.0.0
  
  
      ////////////////////////////////////////////////////Connecting to Server//////////////////////////////////////////////////
      int connection_status;
      connection_status = connect(network_socket, (struct sockaddr*)&server_address, sizeof(server_address)); 


      ///////////////////////////////////////////////////Checking for Connection Status////////////////////////////////////////
      if(connection_status == -1)
        printf("Error occur during creating the connection.\n");


      ///////////////////////////////////////////////////Receiving data from tcp server///////////////////////////////////////
      recv(network_socket, &server_response, sizeof(server_response),0);
  

      ///////////////////////////////////////////////////Response Received by Client from Server//////////////////////////////
      if(connection_status != -1)
        printf("%s",server_response);
  

      ///////////////////////////////////////////////////Shuting Down Socket////////////////////////////////////////////////
      //shutdown(network_socket, 2); 
  

      ////////////////////////////////////////////////////Closing Socket///////////////////////////////////////////////////
      close(network_socket);
  
      return 0;
}



/*
 Commands to know about process id etc
 ps -efa | grep a.out            = process_id
 a.out &                         = process_id
 netstat -natp | grep process_id = listening port
 */


