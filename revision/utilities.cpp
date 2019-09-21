#include "utilities.h"

void eraseUnnecessarySpaces(std::string &str, char c) {
	std::size_t found = 0;

	while ((found = str.find_first_of(" ", found)) != std::string::npos) {
		if ((found == 0) || (found == (str.size() - 1)))
			str.erase(found, 1);
		else if ((str[found + 1] == ' ') || (str[found + 1] == c)
				|| (str[found - 1] == c))
			str.erase(found, 1);	
		else
			found++;
	}
}

void eraseCarriageReturn(std::string &str) {
	std::size_t found = 0;
	
	if ((found = str.find_last_of('\r')) != std::string::npos)
		str.erase(found, 1);
}

void convertTabToSpace(std::string &str) {
	std::size_t found = 0;
	std::string aux = "";
	
	while ((found = str.find_first_of('\t', found)) != std::string::npos)
		str.replace(found, 1, aux);
}
