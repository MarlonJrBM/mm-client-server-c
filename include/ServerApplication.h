#ifndef SERVER_APPLICATION_H
#define SERVER_APPLICATION_H

#include "Ranking.h"

namespace TP1 {

const bool LOGGING = false;

class ServerApplication {

public:
    int runApp(int, char**);

    ~ServerApplication();

private:
    Ranking* _timeRanking = NULL;

    bool isClosingSignal(std::string);

    long long convertMessageToTime(std::string);
	
};


} //namespace

#endif
