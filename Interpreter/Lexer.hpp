#include "Token.hpp"
#include <vector>

class Lexer
{
public:
	Lexer(const std::string& input);
	std::vector<Token> Tokenize();

private:
	std::string input;
	std::vector<Token> tokens;
};
