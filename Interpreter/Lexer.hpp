#include "Token.hpp"
#include <vector>

#pragma once

class Lexer
{
public:
	Lexer(const std::string& input);
	std::vector<Token> Tokenize();

private:
	std::string input;
	std::vector<Token> tokens;
};
