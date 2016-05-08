#include "Server.h"

#include <iostream>

#include "ClientInterface.h"
#include "ServerApplication.h"

using namespace std;
using namespace TP1;

const unsigned MAX_NUM_CONNECTIONS = 7;
const unsigned MAX_BUF = 101;

void Server::setUp(string port) {

    //helper variable to check for errors
    int returnCode = -1; 
    if (LOGGING) {
        cout << "Binding server..." << endl;
    }
    
    _serverSocketId = socket(AF_INET6, SOCK_STREAM, 0);
    
    if (_serverSocketId < 0) {
        cout << "ERROR setting up socket" << endl;
        exit(1);
    }
    
    //Initializing socket structure
    //in6addr_any allows connection from both ipv6 and ipv4
    bzero(&_serverSocket, sizeof(_serverSocket));
    _serverSocket.sin6_family = AF_INET6;
    _serverSocket.sin6_port = htons(stoi(port));
    _serverSocket.sin6_addr = in6addr_any;


    _addrLen = sizeof(_clientSocketId);

    returnCode = bind(_serverSocketId, (sockaddr*) &_serverSocket, sizeof(_serverSocket));
    if (returnCode < 0 ) {
        cout << "ERROR binding server socket." << endl;
        cout << "Maybe try a different port?" << endl;
        exit(1);
    }

    listen(_serverSocketId, MAX_NUM_CONNECTIONS );
}

void Server::closeConnection(int clientId) {
    if (LOGGING) {
        cout << "Closing connection to client..." << endl;
    }

    //TODO - remove client from _clientList (in the future)
    
    sendMessageToClient(clientId, "-1");
    close(clientId);

    if (LOGGING) {
        cout << "Client is out" << endl;
    }
}

int Server::acceptClient() {
    if (LOGGING) {
        cout << "Waiting for client" << endl;
    }
    
    int clientId = accept(_serverSocketId, (sockaddr*) &_clientSocketId, &_addrLen );

    //TODO - Implement and return the Client object in the near future
    //For now, the server only takes one client at a time, so no need
    //for it. An int will suffice
    
    if (LOGGING) {
        cout << "Client accepted..." << endl;
    }

    return clientId;
}

string Server::getMessageFromClient(int clientId) {
    if (LOGGING) {
        cout << "Waiting for client message" << endl;
    }

    char msg[MAX_BUF];
    
    recv(clientId,msg,MAX_BUF, 0);

    if (LOGGING) {
        cout << "Got client message: " << msg << endl;
    }
   
    return string(msg);

}


void Server::sendMessageToClient(int clientId, string message) {
    if (LOGGING) {
        cout << "Sending message to client: " << message << "." << endl;
    }

   send(clientId, message.c_str(), message.size()+1, 0); 
}
