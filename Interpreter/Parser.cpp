#include "Parser.hpp"

//5 + 3 * 4
//5+3*4

// + or -
Expr Parser::expression() {
	Expr left = term();
	while (toks[current].Type == TokenType::PLUS || toks[current].Type == TokenType::MINUS) {
		std::string op = toks[current].value;
		current++;
		Expr right = factor();
		left = Binary(left, right, op);
	}

	return left;
}

// * or /
Expr Parser::term() {
	Expr left = factor();
	while (toks[current].Type == TokenType::ASTERISK) {
		std::string op = toks[current].value;
		current++;
		Expr right = factor();
		left = Binary(left, right, op);
	}

	return left;
}

//numbers like 5
Expr Parser::factor() {
	if (toks[current].Type == TokenType::INT) {
		Number left(toks[current].value);
		current++;
		return left;
	}
}

Expr Parser::parse() {
	auto e = expression();
	return e;
}