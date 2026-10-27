#include <string>

enum class TokenType {
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