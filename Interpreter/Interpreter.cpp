#include <iostream>
#include "Lexer.hpp"
#include "Parser.hpp"

int main()
{
	Lexer lexer("3 + 2 * 5;");
	std::vector<Token> tokens = lexer.Tokenize();
	Parser p(tokens);
	auto par = p.parse();
	std::cout << par->eval();
}

