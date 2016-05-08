#ifndef STRINGMANIP_H
#define STRINGMANIP_H

#include <iostream>
#include <cstdio>
#include <sstream>
#include <vector>

namespace TP1{

std::vector<std::string> getWordsFromString(std::string s) {
	std::vector<std::string> result;
	std::string word;
	std::stringstream stream(s);

	while (stream >> word) {
		result.push_back(word);
	}
	return result;
}

} //namespace

#endif
