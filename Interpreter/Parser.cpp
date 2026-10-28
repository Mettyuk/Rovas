#include "Parser.hpp"

//5 + 3 * 4
//5+3*4

// + or -
std::unique_ptr<Expr> Parser::expression() {
	std::unique_ptr<Expr> left = term();
	while (toks[current].Type == TokenType::PLUS || toks[current].Type == TokenType::MINUS) {
		std::string op = toks[current].value;
		current++;
		std::unique_ptr<Expr> right = std::move(term());
		left = std::make_unique<Binary>(std::move(left), std::move(right), op);
	}

	return left;
}

// * or /
std::unique_ptr<Expr> Parser::term() {
	std::unique_ptr<Expr> left = factor();
	while (toks[current].Type == TokenType::ASTERISK) {
		std::string op = toks[current].value;
		current++;
		std::unique_ptr<Expr> right = std::move(factor());
		left = std::make_unique<Binary>(std::move(left), std::move(right), op);
	}

	return left;
}

//numbers like 5
std::unique_ptr<Expr> Parser::factor() {
	if (toks[current].Type == TokenType::INT) {
		std::unique_ptr<Number> left = std::make_unique<Number>(toks[current].value);
		current++;
		return left;
	}
}

std::unique_ptr<Expr> Parser::parse() {
	std::unique_ptr<Expr> e = std::move(expression());

	return e;
}