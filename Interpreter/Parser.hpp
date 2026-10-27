#include "Lexer.hpp"
#include <vector>

struct Expr
{
	Expr() = default;
	virtual ~Expr() = default;
};

class Binary : Expr
{
public:
	Expr left;
	char opr;
	Expr right;

	Binary(Expr l, Expr r, char o) : left(std::move(l)), right(std::move(r)), opr(std::move(o))
	{
	};
private:

};

class Number
{
public:
	Number(std::string value) : number(std::stoi(value))
	{
	};

	int number;

private:

};


class Parser
{
public:
	Parser(std::vector<Token> tokens) : toks(std::move(tokens)) 
	{
	};
	

private:
	std::vector<Token> toks;
};