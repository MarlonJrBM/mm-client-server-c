#include "ServerMediator.h"

#include <iostream>
#include <cstdio>

using namespace std;
using namespace TP1;

const unsigned int MAX_BUF = 101;

/************************************
* Opens socket to server based on
* addr and port. Returns 0 on success
* and -1 if bind fails.
************************************/
int ServerMediator::connectToServer(string addr, unsigned port) {
    if (_logging) {
        cout << "Connecting to Server " << addr << ":" << port << endl;
    }
    //Variables used to determine address (IPv4 vs IPv6)
	int returnCode = -1; 
    in6_addr serverAddr;
    addrinfo hints;
    addrinfo* result;

    //Hints structure will hold information about address
    bzero(&hints, sizeof(hints));
    hints.ai_flags    = AI_NUMERICSERV;
    hints.ai_family   = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM; 

    returnCode = inet_pton(AF_INET, addr.c_str(), &serverAddr);
    if (returnCode == 1) {  /* this is a valid IPv4 (number format) */
       hints.ai_family = AF_INET;
       hints.ai_flags |= AI_NUMERICHOST;
    } else {
       returnCode = inet_pton(AF_INET6, addr.c_str(), &serverAddr);
       if (returnCode == 1) { /* this is a valid IPv6 (number format) */
          hints.ai_family = AF_INET6;
          hints.ai_flags |= AI_NUMERICHOST;
       }
    }

    returnCode = getaddrinfo(addr.c_str(), to_string(port).c_str() ,&hints, &result);

    if (returnCode < 0 ) {
        cout << "ERROR when resolving server address" << endl;
        exit(1);
    }

    _serverSocketId = socket(result->ai_family, result->ai_socktype,result->ai_protocol);

    //Connects
    return connect(_serverSocketId, result->ai_addr, result->ai_addrlen);

}

/************************************
* Closes connection to server
* 
* 
************************************/
void ServerMediator::closeConnection() {
	if (_logging) {
		cout << "Closing connection" << endl;
	}
}


/************************************
* Gets position back from server 
* (as stringt)
*
************************************/
string ServerMediator::getResponse() {
	if (_logging) {
		cout << "Waiting response from server" << endl;
	}

    char msg[MAX_BUF];

    recv(_serverSocketId, msg, MAX_BUF, 0);

	  return string(msg);
}

/************************************
* Sends client's time to server
* (as long long int)
*
************************************/
void ServerMediator::sendRequest(string clientTime) {
	if (_logging) {
		cout << "Sending request to server: " << clientTime << endl;
	}
   
    send(_serverSocketId,clientTime.c_str(), clientTime.size()+1,0);
}

