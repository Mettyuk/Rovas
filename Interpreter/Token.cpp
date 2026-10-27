#include <string>

enum TokenType {
	INT,
	PLUS,
	ASTERISK,
	SEMICOLON,
	EQUALS,
};

struct Token
{
	std::string value;
	TokenType Type;
};