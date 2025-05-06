#include <iostream>
#include <sstream>
#include <vector>
#define CATCH_CONFIG_MAIN
#include "../../../Catch/catch.hpp"
#include "../NotationParser/ExpressionParser.h"


SCENARIO("Basic Tests")
{
	ExpressionParser expressionParser;

	WHEN("Basic test 1.")
	{
		std::string input = "(+ 7)";
		THEN("Expected result = 7")
		{
			int result = expressionParser.EvaluateExpression(input);
			CHECK(result == 7);
		}
	}

	WHEN("Basic test 2.")
	{
		std::string input = "(* 8)";
		THEN("Expected result = 8")
		{
			int result = expressionParser.EvaluateExpression(input);
			CHECK(result == 8);
		}
	}

	WHEN("Basic test 3.")
	{
		std::string input = "(+ 2 3)";
		THEN("Expected result = 5")
		{
			int result = expressionParser.EvaluateExpression(input);
			CHECK(result == 5);
		}
	}

	WHEN("Basic test 4.")
	{
		std::string input = "(+ 2 3 4)";
		THEN("Expected result = 9")
		{
			int result = expressionParser.EvaluateExpression(input);
			CHECK(result == 9);
		}
	}

	WHEN("Basic test 5.")
	{
		std::string input = "(* 2 4)";
		THEN("Expected result = 8")
		{
			int result = expressionParser.EvaluateExpression(input);
			CHECK(result == 8);
		}
	}

	WHEN("Basic test 6.")
	{
		std::string input = "(* 2 3 4)";
		THEN("Expected result = 24")
		{
			int result = expressionParser.EvaluateExpression(input);
			CHECK(result == 24);
		}
	}

	WHEN("Basic test 7.")
	{
		std::string input = "(+ -2 3)";
		THEN("Expected result = 1")
		{
			int result = expressionParser.EvaluateExpression(input);
			CHECK(result == 1);
		}
	}
}

SCENARIO("Nested expression Tests")
{
	ExpressionParser expressionParser;

	WHEN("Tests with nested expression 1.")
	{
		std::string input = "(+ (* 2 3) (* 3 4))";
		THEN("Expected result = 18")
		{
			int result = expressionParser.EvaluateExpression(input);
			CHECK(result == 18);
		}
	}

	WHEN("Tests with nested expression 2.")
	{
		std::string input = "(* (+ 1 2) (+ 3 1))";
		THEN("Expected result = 12")
		{
			int result = expressionParser.EvaluateExpression(input);
			CHECK(result == 12);
		}
	}

	WHEN("Tests with nested expression 3.")
	{
		std::string input = "(+ 5 (* 2 3 2) (+ 5 (+ 2 5) (* 2 2)))";
		THEN("Expected result = 33")
		{
			int result = expressionParser.EvaluateExpression(input);
			CHECK(result == 33);
		}
	}

	WHEN("Large numbers test.")
	{
		std::string input = "(+ 999999999 1)";
		THEN("Expected result = 1000000000")
		{
			int result = expressionParser.EvaluateExpression(input);
			CHECK(result == 1000000000);
		}
	}

	WHEN("Deep nesting test.")
	{
		std::string input = "(+ (+ (+ 1)))";
		THEN("Expected result = 1")
		{
			int result = expressionParser.EvaluateExpression(input);
			CHECK(result == 1);
		}
	}
}

SCENARIO("Brackets Tests")
{
	ExpressionParser expressionParser;

	WHEN("Closing Brace is missing.")
	{
		std::string input = "(+ 1 2";
		THEN("Expected Invalid expression")
		{
			REQUIRE_THROWS_AS(expressionParser.EvaluateExpression(input), std::runtime_error);
		}
	}

	WHEN("Mismatched Brackets")
	{
		std::string input = ") + 1 2 (";
		THEN("Expected Mismatched bracket")
		{
			REQUIRE_THROWS_AS(expressionParser.EvaluateExpression(input), std::runtime_error);
		}
	}

	WHEN("Invalid expression")
	{
		std::string input = "(+ (* 1 2) 3";
		THEN("Expected Invalid expression")
		{
			REQUIRE_THROWS_AS(expressionParser.EvaluateExpression(input), std::runtime_error);
		}
	}
}


SCENARIO("Operator Tests")
{
	ExpressionParser expressionParser;

	WHEN("Unsupproted Operator.")
	{
		std::string input = "(- 1 2)";
		THEN("Expected Invalid operator")
		{
			REQUIRE_THROWS_AS(expressionParser.EvaluateExpression(input), std::runtime_error);
		}
	}

	WHEN("Unsupproted Operator.")
	{
		std::string input = "(/ 1 2)";
		THEN("Expected Invalid operator")
		{
			REQUIRE_THROWS_AS(expressionParser.EvaluateExpression(input), std::runtime_error);
		}
	}

	WHEN("Null Operator.")
	{
		std::string input = "(1 2 3)";
		THEN("Expected Invalid operator")
		{
			REQUIRE_THROWS_AS(expressionParser.EvaluateExpression(input), std::runtime_error);
		}
	}
}

SCENARIO("Argument Tests")
{
	ExpressionParser expressionParser;
	
	WHEN("Non-Numeric Argument.")
	{
		std::string input = "(+ 1 abc)";
		THEN("Expected Invalid argument")
		{
			REQUIRE_THROWS_AS(expressionParser.EvaluateExpression(input), std::runtime_error);
		}
	}

	WHEN("Empty Argument.")
	{
		std::string input = "(+ )";
		THEN("Expected No arguments for operator")
		{
			REQUIRE_THROWS_AS(expressionParser.EvaluateExpression(input), std::runtime_error);
		}
	}

	WHEN("Non Argument.")
	{
		std::string input = "(+)";
		THEN("Expected No arguments for operator")
		{
			REQUIRE_THROWS_AS(expressionParser.EvaluateExpression(input), std::runtime_error);
		}
	}

	WHEN("An empty Enclosed expression.")
	{
		std::string input = "(+ (*) (+ 1 2))";
		THEN("Expected No arguments for operator")
		{
			REQUIRE_THROWS_AS(expressionParser.EvaluateExpression(input), std::runtime_error);
		}
	}

	WHEN("Empty Expression")
	{
		std::string input = "(+ ())";
		THEN("Expected Empty expression")
		{
			REQUIRE_THROWS_AS(expressionParser.EvaluateExpression(input), std::runtime_error);
		}
	}

	WHEN("Empty Expression")
	{
		std::string input = "(+ 1 () 2)";
		THEN("Expected Empty expression")
		{
			REQUIRE_THROWS_AS(expressionParser.EvaluateExpression(input), std::runtime_error);
		}
	}
}


SCENARIO("Out of bounds Tests")
{
	ExpressionParser expressionParser;
	
	WHEN("Out of bounds.")
	{
		std::string input = "(+ 1 9999999999999999999)";
		THEN("Expected Argument out of range")
		{
			REQUIRE_THROWS_AS(expressionParser.EvaluateExpression(input), std::runtime_error);
		}
	}

	WHEN("Out of bounds.")
	{
		std::string input = "(+ (* 999999999999999 2))";
		THEN("Expected Argument out of range")
		{
			REQUIRE_THROWS_AS(expressionParser.EvaluateExpression(input), std::runtime_error);
		}
	}

	WHEN("Out of bounds.")
	{
		std::string input = "()";
		THEN("Expected Empty expression")
		{
			REQUIRE_THROWS_AS(expressionParser.EvaluateExpression(input), std::runtime_error);
		}
	}
}