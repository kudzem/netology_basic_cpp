#include "GreetingLib.h"

void 
MyGreetingLib::greet(std::string& who_to_greet) {
	std::cout << "Здравствуйте, " << who_to_greet << "!" << std::endl;
}