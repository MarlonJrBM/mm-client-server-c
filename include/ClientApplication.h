#ifndef CLIENTAPPLICATION_H
#define CLIENTAPPLICATION_H

#include "ServerMediator.h"
#include <cstdio>
#include <iostream>

namespace TP1{

class ClientApplication {

public:
	int runApplication(int,char**);

private:
	const static bool _logging = false;
	ServerMediator _mediator;
	std::string getClientInput();
	long long convertTime(std::string);
	void displayResponse(std::string);


};

} //namespace







#endif
