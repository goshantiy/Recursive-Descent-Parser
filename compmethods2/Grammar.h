#pragma once
#include <string>
#include <vector>
#include <map>

class Grammar {
public:
	struct Rule {
		char leftRule;
		std::string rightRule;
		explicit Rule(char left, std::string right) : leftRule(left), rightRule(right) {}
	};

	struct RuleId {
		int ruleId;
		RuleId() {}
		explicit RuleId(int Id) : ruleId(Id) {}
	};

	explicit Grammar(std::vector<Rule>& rules, std::map<char, RuleId>& nonterminals, std::string& terminals);

	bool isTerminal(char a);

	std::vector<Rule> R;
	std::map<char, RuleId> N;
	std::string T;
	char initialChar;
};
