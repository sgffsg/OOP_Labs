#pragma once
#include "Bank.h"

class Actor
{
public:
	void GetCash();
	void GetBalance();

private:
	Money money;
};
