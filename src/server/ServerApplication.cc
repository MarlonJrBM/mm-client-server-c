#include "ServerApplication.h"

#include <iostream>

#include "Server.h"
#include "Ranking.h"
#include "ClientInterface.h"

using namespace std;
using namespace TP1;

Server* Server::_serverInstance = NULL;

int ServerApplication::runApp(int argc, char** argv) {

    //Local and helper variables
    int curClient = 0;
    string clientMessage = "";
    string position = "";
    string port = argv[1];
    
    if (LOGGING) {
        cout << "Starting server!" << endl;
        cout << "Number of arguments: " << argc << endl;
        cout << "Press ctrl + c at anytime to exit" << endl;
    }

    Server* server = Server::getInstance();

    //Sets up server configuration and structures
    server->setUp(port);

    //initializes structure to handle race times
    _timeRanking = new Ranking();

    //Server's main loop
    while (true) {

        //Below calls are blocking, will wait until
        //Client connects and send their time in the race
        curClient = server->acceptClient();
        do {
            clientMessage = server->getMessageFromClient(curClient);        
            //Checks if client wants to close connection
            if (isClosingSignal(clientMessage)) {
                _timeRanking->clear();
                server->closeConnection(curClient);
             } else {
                //Will handle user request, sending his/her
                //position back
                 position = _timeRanking->insert(clientMessage);
                 cout << position << endl;
                 server->sendMessageToClient(curClient, position);
             }

        } while (!isClosingSignal(clientMessage));
    }
    
    //Will never reach below lines in single-threaded version
    server->stop();

    return 0;

}

bool ServerApplication::isClosingSignal(string message) {
    int signal = stoi(message);

    if (signal < 0) 
        return true;
    else
        return false;
}

ServerApplication::~ServerApplication() {
    Server::deleteInstance();
    if (!_timeRanking) delete(_timeRanking);
}

