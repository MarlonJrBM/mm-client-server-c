#ifndef SERVER_H
#define SERVER_H

#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>

#include "ClientInterface.h"


namespace TP1{

enum IP_TYPE { IPV4, IPV6};

typedef std::vector<Client> ClientList;

/*************************
 * Singleton Server class
 *************************/
class Server {
    
    public:
       
        //There can only be one server, which will be initialized on demand
        static Server* getInstance() {
            if (_serverInstance == NULL) {
                _serverInstance = new Server();
            }
            return _serverInstance;
        }

        static void deleteInstance() {
            if (_serverInstance->_serverSocketId != -1) {
                close(_serverInstance->_serverSocketId);
            }

            if (_serverInstance->_clientSocketId != -1) {
                close(_serverInstance->_clientSocketId);
            }

            if (_serverInstance != NULL) {
                delete _serverInstance;
            }
        }

        void setUp(std::string port);

        void run(); //NOT IMPLEMENTED

        void stop(); //NOT IMPLEMENTED
        
        //Accepts a client, adds it to _clientList (TODO), and returns a reference to it
        int acceptClient();

        void sendMessageToClient(int, std::string);

        std::string getMessageFromClient(int);

        //Closes connection to client and removes him/her from _clientList
        void closeConnection(int);

    
    private:
        static Server* _serverInstance;
        Server() {};
        ClientList _clientList;
        sockaddr_in6 _serverSocket;
        int _serverSocketId, _clientSocketId;
        unsigned _addrLen;



};

} //namespace

#endif

