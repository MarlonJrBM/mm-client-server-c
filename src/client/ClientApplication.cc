#include "ClientApplication.h"

#include <iostream>
#include <cstdio>
#include <string>
#include <regex>

#include "StringManip.h"

using namespace std;
using namespace TP1;

/**
 * Client's application main loop
 *
 * */
int ClientApplication::runApplication(int argc, char** argv) {
	string clientTime = "";
	long long convertedTime = 0;
    string addr = argv[1];
    string port = argv[2];
    int connectionFlag = -1;

	if (_logging) cout << "Starting Client Application" << endl;
    if (_logging) cout << "Number of arguments: " << argc << endl;
    
	connectionFlag = _mediator.connectToServer(addr.c_str(), stoul(port));
    if (connectionFlag != 0 ) {
        cout << "ERROR! Could not bind to server at " << addr <<  ":" << port << endl;
        exit(1);
    }

	do {
		clientTime = getClientInput();
		convertedTime = stoll(clientTime);

		//sends converted time to server
		_mediator.sendRequest(clientTime);

		//gets position back from server and display it on screen
		displayResponse(_mediator.getResponse());

	} while (convertedTime >= 0);

	_mediator.closeConnection();

	return 0;
}

void ClientApplication::displayResponse(string position) {

    if (stoll(position) >= 0) {
	    cout << position << endl;
    } else {
        //Server is ending connection
        if (_logging) {
            cout << "Exiting client" << endl;
        }
    }
}

string ClientApplication::getClientInput() {
	string clientTime;
	if (_logging) {
		cout << "Please type your time" << endl;
	}
	getline(cin, clientTime);
	return clientTime;
}
