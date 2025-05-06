#pragma once
#include "BankOperationStatus.h"

using AccountId = unsigned long long;
using Money = long long;

class BankAccount
{
public:
	AccountId GetAccountId();
	Money GetAccountBalace();	

	BankOperationStatus IncreaseBalance(Money amount);
	BankOperationStatus DecreaseBalance(Money amount);

private:
	AccountId	m_accountId;
	Money m_accountBalance;
};
