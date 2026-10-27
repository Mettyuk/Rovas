#include "Lexer.hpp"
#include <vector>

struct Expr
{
	Expr() = default;
	virtual ~Expr() = default;
};

class Binary : public Expr
{
public:
	Expr left;
	std::string opr;
	Expr right;

	Binary(Expr l, Expr r, std::string o) : left(std::move(l)), right(std::move(r)), opr(std::move(o))
	{
	};
private:

};

class Number : public Expr
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
	
	Expr expression();
	Expr term();
	Expr factor();

	int current = 0;

	Expr parse();

private:
	std::vector<Token> toks;
};