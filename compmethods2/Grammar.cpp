#include "Grammar.h"
Grammar::Grammar(std::vector<Rule>& rules, std::map<char, RuleId>& nonterminals, std::string& terminals) :R(rules), N(nonterminals), T(terminals)
{
	initialChar = 'A';
}

bool Grammar::isTerminal(char a)
{
	if (T.find(a) == -1)
		return false;
	return true;
}
