#include <iostream>
#include "Lexer.hpp"

int main()
{
	Lexer lexer("3 + 2 * 5");
	std::vector<Token> tokens = lexer.Tokenize();
	int asd;
	std::string dsa = "asd";
	std::cout << dsa.substr(2, 2);
}

