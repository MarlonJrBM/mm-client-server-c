#ifndef RANKING_H
#define RANKING_H

#include <set>

#include "ClientInterface.h"


namespace TP1 {

class Ranking {

public:

    //Inserts time into ranking and returns the associated position
    std::string insert(std::string);
    void clear();

private:
    std::multiset<unsigned> _rankingContainer;

    unsigned long long convertMessageToTime(std::string);
};

} //namespace

#endif
