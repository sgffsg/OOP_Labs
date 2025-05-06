#include "ExpressionParser.h"
#include <stack>

int ExpressionParser::EvaluateExpression(const std::string& expression)
{
	std::stack<std::vector<std::string>> stack;
	std::vector<std::string> tokens = Tokenize(expression);

	for (size_t i = 0; i < tokens.size(); ++i)
	{
		const std::string& token = tokens[i];
		if (token == "(")
		{
			stack.push(std::vector<std::string>());
		}
		else if (token == ")")
		{
			int result = HandleCloseBracket(stack);
			if (stack.empty())
			{
				return result;
			}
			stack.top().push_back(std::to_string(result));
		}
		else
		{
			HandleToken(stack, token);
		}
	}

	throw std::runtime_error("Invalid expression");
}


int ExpressionParser::HandleCloseBracket(std::stack<std::vector<std::string>>& stack)
{
	if (stack.empty())
	{
		throw std::runtime_error("Mismatched bracket");
	}

	std::vector<std::string> current = stack.top();
	stack.pop();

	if (current.empty())
	{
		throw std::runtime_error("Empty expression");
	}

	std::string op = current[0];
	if (!IsOperator(op))
	{
		throw std::runtime_error("Invalid operator");
	}

	std::vector<int> args = ParseArguments(current);
	return ApplyOperator(op[0], args);
}

std::vector<int> ExpressionParser::ParseArguments(const std::vector<std::string>& current)
{
	std::vector<int> args;
	for (size_t j = 1; j < current.size(); ++j)
	{
		try
		{
			args.push_back(stoi(current[j]));
		}
		catch (const std::invalid_argument&)
		{
			throw std::runtime_error("Invalid argument");
		}
		catch (const std::out_of_range&)
		{
			throw std::runtime_error("Argument out of range");
		}
	}
	return args;
}

void ExpressionParser::HandleToken(std::stack<std::vector<std::string>>& stack, const std::string& token)
{
	if (stack.empty())
	{
		throw std::runtime_error("Invalid expression");
	}
	stack.top().push_back(token);
}

std::vector<std::string> ExpressionParser::Tokenize(const std::string& expression)
{
	std::vector<std::string> tokens;
	std::string token;
	for (char c : expression)
	{
		if (c == '(' || c == ')')
		{
			if (!token.empty())
			{
				tokens.push_back(token);
				token.clear();
			}
			tokens.push_back(std::string(1, c));
		}
		else if (isspace(c))
		{
			if (!token.empty())
			{
				tokens.push_back(token);
				token.clear();
			}
		}
		else
		{
			token += c;
		}
	}
	if (!token.empty())
	{
		tokens.push_back(token);
	}
	return tokens;
}

bool ExpressionParser::IsOperator(const std::string& token)
{
	return token == "+" || token == "*";
}

int ExpressionParser::ApplyOperator(const char expressionOperator, const std::vector<int> arguments)
{
	if (arguments.empty())
	{
		throw std::runtime_error("No arguments for operator");
	}

	int operationResult;
	switch (expressionOperator)
	{
	case '+':
		operationResult = 0;
		for (int arg : arguments)
		{
			operationResult += arg;
		}
		return operationResult;
	case '*':
		operationResult = 1;
		for (int arg : arguments)
		{
			operationResult *= arg;
		}
		return operationResult;
	default:
		throw std::runtime_error("Unknown operator");
		break;
	}
}
