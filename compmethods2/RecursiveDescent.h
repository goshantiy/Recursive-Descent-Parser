#pragma once
#include "Grammar.h"
#include <string>
#include <iostream>
#include <stack>
#include <list>
enum letters
{
	a, b, c, d, x
};
enum operators
{
	plus = '+', minus = '-', multiply = '*', division = '/'};
class RecursiveDescent {
public:
	RecursiveDescent();
	bool parser(const std::string&);
	bool isOperator(char);
	bool isLetter(char);
	bool isRight(char);
	bool isLeft(char);
	bool B();
	bool T();
	bool M();
	void printList();	
	int count;
	std::list<char> result;
	std::stack<char> checkBalance;
	std::string input;
	int pos;
};