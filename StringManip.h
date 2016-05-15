#ifndef STRING_MANIP_H
#define STRING_MANIP_H

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

} //namespace TP1

#endif
