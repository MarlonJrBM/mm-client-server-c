#ifndef CLIENT_INTERFACE_H
#define CLIENT_INTERFACE_H

#include <iostream>

namespace TP1 {

/*************************************************
 * This is the Client interface used by the Server
 ************************************************/
class Client {

public:
    Client(std::string addr) : _addr(addr) {};

private:
    std::string _addr;

};
} //namespace TP1

#endif
