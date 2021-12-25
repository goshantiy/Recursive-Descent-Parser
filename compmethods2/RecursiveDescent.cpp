#include "RecursiveDescent.h"

bool RecursiveDescent::isOperator(char sym)
{
	if (sym == '+') return true;
	if (sym == '-') return true;
	if (sym == '*') return true;
	if (sym == '/') return true;
	else return false;
}
bool RecursiveDescent::isLetter(char sym)
{
	if (sym == 'a') return true;
	if (sym == 'b') return true;
	if (sym == 'c') return true;
	if (sym == 'd') return true;
	if (sym == 'x') return true;
	else return false;
}
bool RecursiveDescent::isLeft(char sym)
{
	if (sym == '(') return true;
	else return false;
}
bool RecursiveDescent::isRight(char sym)
{
	if (sym == ')') return true;
	else return false;
}
bool RecursiveDescent::B()
{
	result.push_back(2);//B
	bool b = T();
	if (isOperator(input[pos - 1])) 
		b = false;
	if (b)
	{
		while (input[pos] == '+'|| input[pos] == '-')
		{
			if (isOperator(input[pos - 1]) || input[pos + 1] == '!') return false;
			else
			{
				pos++;
				b = T();
				if (!b) return false;
			}
		}
	}
	return b;
}

bool RecursiveDescent::T()
{
	result.push_back(3);//T
	bool b = M();

	if (b)
	{
		while (input[pos] == '*' || input[pos] == '/')
		{
			if (isOperator(input[pos - 1]) || input[pos + 1] == '!') return false;
			else
			{
				pos++;
				b = T();
			}
		}
	}
	
	if (!isLetter(input[pos-1])&&isLeft(input[pos]))
		b = M();
	return b;
}
bool RecursiveDescent::M()
{
	result.push_back(4);
	if (isLeft(input[pos]))
	{
		if (isRight(input[pos-1])) return false;
		pos++;
		if (isRight(input[pos])) return false;//случай ();
		else 
		{
			checkBalance.push(input[pos-1]);
			if (isOperator(input[pos])||isRight(input[pos+1])) return false;//(+ (b)
			else 
			{
				bool b = B();
			}
		}
		
	}
	if (isRight(input[pos]))
	{
		if (isOperator(input[pos - 1]) || isLetter(input[pos + 1])) return false;//+)a
		if (!checkBalance.empty())//проверяем баланс скобок
		{
			char check = checkBalance.top();
			if (check != '(') return false;
			checkBalance.pop();
			pos++;
			return true;
		}
		return false;
	}
	
	if (isLetter(input[pos]))
	{
		result.push_back('U');
		count++;
		pos++;
		if(isRight(input[pos]) || isLetter(input[pos]) || isLeft(input[pos]))//проверяем что после символа
			return false;
		else return true;
	}
	if (isOperator(input[pos]))
	{
		if (input[pos - 1] == '!' || input[pos + 1] == '!') return false;
		return true;
	}
	if (input[pos] == '!'&&checkBalance.empty())//конец строки и соблюден баланс скобок
		return true;
	else
		return false;
}
RecursiveDescent::RecursiveDescent()
{
}
bool RecursiveDescent::parser(const std::string& str)
{
	int n = str.length();
	pos = 0;
	count = 0;
	input = str;
	result.clear();
	while (!checkBalance.empty())
		checkBalance.pop();
	if (n > 1 && str[0] == '!' && str[n-1] == '!')
	{
		pos++;
		result.push_back(1);//A
		bool b = B();
		return b;
	} 
	return false;
}
void RecursiveDescent::printList() {
	for (auto it : result)
		if (it == 'U')
			std::cout << it << ' ';
		else
		std::cout << (int)it<<' ';
	std::cout << std::endl;
}