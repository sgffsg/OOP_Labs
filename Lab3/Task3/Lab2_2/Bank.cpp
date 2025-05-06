#include "Bank.h"

Bank::Bank(Money cash)
	: cash(cash)
{
	if (cash < 0)
	{
		throw BankOperationError("Initial cash cannot be negative");
	}
}

void Bank::ValidateAmount(Money amount) const
{
}

void Bank::ValidateAccount(AccountId accountId) const
{
}



Money Bank::GetAccountBalance(AccountId accountId) const
{
}

void Bank::WithdrawMoney(AccountId accountId, Money amount)
{
}

void Bank::DepositMoney(AccountId accountId, Money amount)
{
}

void Bank::SendMoney(AccountId srcAccountId, AccountId dstAccountId, Money amount)
{
}

Money Bank::GetCash() const
{
	
}

bool Bank::TrySendMoney(AccountId srcAccountId, AccountId dstAccountId, Money amount)
{
	
}

bool Bank::TryWithdrawMoney(AccountId accountId, Money amount)
{
	
}

AccountId Bank::OpenAccount()
{
	
}

Money Bank::CloseAccount(AccountId accountId)
{
	
}
