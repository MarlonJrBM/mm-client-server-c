#ifndef SERVERMEDIATOR_H
#define SERVERMEDIATOR_H

#include <iostream>
#include <cstdio>
#include <cstring>
#include <sys/types.h>
#include <sys/socket.h>    
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <arpa/inet.h>


namespace TP1{
/**
 * This is the Mediator the client uses to communicate with the server.
 *
 * */
class ServerMediator {
public:
	int connectToServer(std::string,unsigned);
	void closeConnection();
    std::string  getResponse();
	void sendRequest(std::string);

private:
	const static bool _logging = true;
    struct sockaddr_in6 _serverSocket; 
    int _serverSocketId;

};




} //namespace








#endif
