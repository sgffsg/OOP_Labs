#include "BankAccount.h"

AccountId BankAccount::GetAccountId()
{
}

Money BankAccount::GetAccountBalace()
{
}

BankOperationStatus BankAccount::IncreaseBalance(Money amount)
{
	m_accountBalance += amount;
	return BankOperationStatus::SUCCESS;
}

BankOperationStatus BankAccount::DecreaseBalance(Money amount)
{
	if (m_accountBalance < amount)
	{
		return BankOperationStatus::FAILURE;
	}

	m_accountBalance += amount;
	return BankOperationStatus::SUCCESS;
}
