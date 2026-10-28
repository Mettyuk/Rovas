#include "Lexer.hpp"
#include <vector>
#include <memory>

#pragma once

struct Expr
{
	Expr() = default;
	virtual ~Expr() = default;
	virtual int eval() = 0;
};

class Binary : public Expr
{
public:
	std::unique_ptr<Expr> left;
	std::string opr;
	std::unique_ptr<Expr> right;

	Binary(std::unique_ptr<Expr> l, std::unique_ptr<Expr> r, std::string o) : left(std::move(l)), right(std::move(r)), opr(std::move(o))
	{
	};

	virtual int eval() {
		int l = left->eval();
		int r = right->eval();

		if (opr == "*") return r * l;
		if (opr == "+") return r + l;
		if (opr == "-") return r - l;
	}

private:

};

class Number : public Expr
{
public:
	Number(std::string value) : number(std::stoi(value))
	{
	};

	int number;

	virtual int eval() {
		return number;
	}

private:

};


class Parser
{
public:
	Parser(std::vector<Token> tokens) : toks(std::move(tokens)) 
	{
	};
	
	std::unique_ptr<Expr> expression();
	std::unique_ptr<Expr> term();
	std::unique_ptr<Expr> factor();

	int current = 0;

	std::unique_ptr<Expr> parse();

private:
	std::vector<Token> toks;
};