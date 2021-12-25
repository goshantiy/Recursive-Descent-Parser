#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <stack>
#include "RecursiveDescent.h"
#include "Grammar.h"


//А :: = !В!
//В :: = Т{ +Т | -Т }
//Т :: = М{ *М|/М }
//М :: = a | b | c | d | x | (В)
void print(RecursiveDescent parser,bool check)
{
	std::cout << parser.input << std::endl;
	//std::cout << "count u = " << parser.count << std::endl;
	if (check)
	{
		std::cout << "PASSED" << std::endl;
		parser.printList();
		std::cout<<std::endl;
	}
	else std::cout << "FAILED" << std::endl;
}
int main()
{
	//std::vector<Grammar::Rule> rules = { Grammar::Rule('A', "!B!"), Grammar::Rule('B', "T{+T|-T}"), Grammar::Rule('T', "M{*M|/M}"), Grammar::Rule('M', "a|b|c|d|x|(B)") };
	//std::map<char, Grammar::RuleId> nonTerminals = { {'A',Grammar::RuleId(0)},{'B',Grammar::RuleId(1)},{'T',Grammar::RuleId(2)},{'M',Grammar::RuleId(3)} };
	//std::string terminals = "!+-*/()abcdx";
	//Grammar grammar(rules, nonTerminals, terminals);
	RecursiveDescent parser;
	std::string input =   "!(a+b+c+d)*c!";
	std::string input1 =  "!(a+b)-(a-c)!";
	std::string input2 =  "!a*b*c*d*d!";
	std::string input3=   "!(a+b-c)/(a-b)!";
	std::string input4 =  "!(a+c-d)*b/d-a!";
	std::string input5 =  "!((a*x+b)*x+c)*x-d!";
	std::string input6 =  "!a/b/d*(a+b)!";
	std::string input7 =  "!a+b*(c-a-b)/d!";
	std::string input8 =  "!a*b-c*d+b/d!";
	std::string input9 =  "!(b+b*b-a*c)/(b+a)!";
	std::string input10 = "!(((a+b)*c)+x)*d/c+x+x!";
	std::string input11 = "!(a+b)*((c+d)*b)+(c-d/b)+a-((b-(x-c)+d)+(d-a)+b)/(x-x)+(a+b/c/d)*c+d/((((d-x)-(a+b)*c+d/(x-x)+(a+b)*c+d/(x-x))))+c+((d-a)+b)/(x-x)!";
	std::string input12 = "!a*b+c-((a+b)-x)!";
	print(parser, parser.parser(input));
	print(parser, parser.parser(input1));
	print(parser, parser.parser(input2));
	print(parser, parser.parser(input3));
	print(parser, parser.parser(input4));
	print(parser, parser.parser(input5));
	print(parser, parser.parser(input6));
	print(parser, parser.parser(input7));
	print(parser, parser.parser(input8));
	print(parser, parser.parser(input9));
	print(parser, parser.parser(input10));
	print(parser, parser.parser(input11));
	print(parser, parser.parser(input12));
}

