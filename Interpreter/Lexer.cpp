#include "Lexer.hpp"

Lexer::Lexer(const std::string& input) {
	this->input = input;
}

std::vector<Token> Lexer::Tokenize() {
	for (int i{ 0 }; i < input.size(); ++i) {
		if (input[i] == ' ') {
			continue;
		}
		if (input[i] == '*') {
			tokens.push_back({ "*", TokenType::ASTERISK });
		}
		if (input[i] == '+') {
			tokens.push_back({ "+", TokenType::PLUS });
		}
		if (input[i] == ';') {
			tokens.push_back({ ";", TokenType::SEMICOLON});
		}
		if (input[i] == '-') {
			tokens.push_back({ "-", TokenType::MINUS });
		}
		if (input[i] == '=') {
			tokens.push_back({ "=", TokenType::EQUALS });
		}
		if (isdigit(input[i])) {
			int start = i;
			int cnt = 1;
			while (isdigit(input[i + 1])) {
				i++;
				cnt++;
			}
			tokens.push_back({ input.substr(start, cnt), TokenType::INT });
		}
	}

	return tokens;
}