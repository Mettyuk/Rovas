#include <iostream>
#include "Lexer.hpp"

int main()
{
	Lexer lexer("3 + 2 * 5");
	std::vector<Token> tokens = lexer.Tokenize();
}

