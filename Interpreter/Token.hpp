#include <string>

#pragma once

enum class TokenType {
	INT,
	PLUS,
	MINUS,
	ASTERISK,
	SEMICOLON,
	EQUALS,
};

struct Token
{
	std::string value;
	TokenType Type;
};