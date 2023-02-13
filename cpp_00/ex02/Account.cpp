#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

int	Account::getNbAccounts(void)
{
	return (_nbAccounts);
}
int	Account::getTotalAmount(void)
{
	return (_totalAmount);
}
int	Account::getNbDeposits(void)
{
	return (_totalNbDeposits);
}
int	Account::getNbWithdrawals(void)
{
	return (_totalNbWithdrawals);
}
void	Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts;
	std::cout << ";total:" << _totalAmount;
	std::cout << ";deosits:" << _totalNbDeposits;
	std::cout << ";withdrawals:" << _totalNbWithdrawals;
	std::cout << std::endl;
}


void	Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex;
	std::cout << ";p_amount:" << _amount;
	std::cout << ";deposit:" << deposit;
	std::cout << ";amount:" << _amount + deposit;
	std::cout << ";nb_deposits:" << _nbDeposits + 1;
	std::cout << std::endl;
	_amount += deposit;
	_totalAmount += deposit;
	_nbDeposits++;
	_totalNbDeposits++;
}

void	Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex;
	std::cout << ";amount:" << _amount;
	std::cout << ";deposits:" << _nbDeposits;
	std::cout << ";withdrawals:" << _nbWithdrawals;
	std::cout << std::endl;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex;
	std::cout << ";p_amount:" << _amount;
	if (_amount >= withdrawal)
	{
		std::cout << ";withdrawal:" << withdrawal;
		std::cout << ";amount:" << _amount - withdrawal;
		std::cout << ";nb_withdrawals:" << _nbWithdrawals + 1;
		std::cout << std::endl;
		_amount -= withdrawal;
		_totalAmount -= withdrawal;
		_nbWithdrawals++;
		_totalNbWithdrawals++;
		return (true);
	}
	std::cout << "refused\n";
	return (false);

}

int	Account::checkAmount(void) const
{
	return (_amount);
}

void	Account::_displayTimestamp(void)
{
	time_t		timer = time(NULL);
	struct tm	*stamp = localtime(&timer);

	std::cout << "[" << (stamp->tm_year + 1900);
	std::cout << std::setfill('0') << std::setw(2) << (stamp->tm_mon + 1);
	std::cout << std::setfill('0') << std::setw(2) << stamp->tm_mday << "_";
	std::cout << std::setfill('0') << std::setw(2) << stamp->tm_hour;
	std::cout << std::setfill('0') << std::setw(2) << stamp->tm_min;
	std::cout << std::setfill('0') << std::setw(2) << stamp->tm_sec;
	std::cout << "] ";
}

Account::Account(int initial_deposit)
{
	_accountIndex = _nbAccounts;
	_nbAccounts++;
	_amount = initial_deposit;
	_totalAmount += _amount;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex;
	std::cout << ";amount:" << _amount;
	std::cout << ";created\n";
}

Account::~Account(void)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex;
	std::cout << ";amount:" << _amount;
	std::cout << ";closed\n";
}

//typedef Account		t;

//static int	getNbAccounts( void );
//static int	getTotalAmount( void );
//static int	getNbDeposits( void );
//static int	getNbWithdrawals( void );
//static void	displayAccountsInfos( void );

//Account( int initial_deposit );
//~Account( void );

//void	makeDeposit( int deposit );
//bool	makeWithdrawal( int withdrawal );
//int		checkAmount( void ) const;
//void	displayStatus( void ) const;

//static void	_displayTimestamp( void );
//Account( void );


//static int	_nbAccounts;
//static int	_totalAmount;
//static int	_totalNbDeposits;
//static int	_totalNbWithdrawals;
//int				_accountIndex;
//int				_amount;
//int				_nbDeposits;
//int				_nbWithdrawals;
