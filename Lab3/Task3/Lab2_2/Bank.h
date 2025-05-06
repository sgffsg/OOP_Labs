#pragma once
#include <stdexcept>
#include <unordered_map>
#include <string>
#include "BankAccount.h"
#include "Actor.h"

using AccountId = unsigned long long;
using Money = long long;

class BankOperationError : public std::runtime_error
{
public:
	using std::runtime_error::runtime_error;
};

// Контролирует все деньги в обороте (как наличные, так и безналичные)
class Bank
{
public:
	explicit Bank(Money cash);
	
	Bank(const Bank&) = delete;
	Bank& operator=(const Bank&) = delete;

	Money GetAccountBalance(AccountId accountId) const;
	
	void ValidateAmount(Money amount) const;
	void ValidateAccount(AccountId accountId) const;

	void WithdrawMoney(AccountId account, Money amount);	
	void DepositMoney(AccountId account, Money amount);
	void SendMoney(AccountId srcAccountId, AccountId dstAccountId, Money amount);

	[[nodiscard]] Money GetCash() const;
	[[nodiscard]] bool TrySendMoney(AccountId srcAccountId, AccountId dstAccountId, Money amount);
	[[nodiscard]] bool TryWithdrawMoney(AccountId account, Money amount);
	[[nodiscard]] AccountId OpenAccount();
	[[nodiscard]] Money CloseAccount(AccountId accountId);

private:
	Money cash;
	std::unordered_map<BankAccount, Actor> clients;
	AccountId nextAccountId = 1;
};