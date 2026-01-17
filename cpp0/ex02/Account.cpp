/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mturgeon <maxime.p.turgeon@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 08:56:52 by mturgeon          #+#    #+#             */
/*   Updated: 2026/01/17 11:38:43 by mturgeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"

int	Account::_totalAmount = 0;
int	Account::_nbAccounts = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

//time_t holds number of sec since epoch (01/01/1970 00:00:00).
//tm is a struc that holds year to secs fields.
//gmtime() populates it nicely w/ current time.
void    Account::_displayTimestamp(void){
	std::time_t timestamp;
	std::tm *t;

	std::time(&timestamp);
	t = gmtime(&timestamp);
	std::cout << "[" << t->tm_year + 1900;
	if (t->tm_mon + 1 < 10)
		std::cout<< "0";
	std::cout<< t->tm_mon + 1;
	if (t->tm_mday + 1 < 10)
        std::cout<< "0";
	std::cout << t->tm_mday << "_";
	if (t->tm_hour + 1 < 10)
        std::cout<< "0";
	std::cout << t->tm_hour + 1;
	if (t->tm_min < 10)
		std::cout<< "0";
	std::cout << t->tm_min;
	if (t->tm_sec < 10)
		std::cout<< "0";
	std::cout <<t->tm_sec << "]";
	return ;
}

Account::Account(int initial_deposit):
_accountIndex(Account::_nbAccounts),
_amount(initial_deposit),
_nbDeposits(0),
_nbWithdrawals(0){
	Account::_nbAccounts++;
	Account::_totalAmount+= this->_amount;
	_displayTimestamp();
	std::cout << " index:" << this->_accountIndex << ";amount:" << this->_amount << ";created" << std::endl; 
	return;
}

Account::~Account(void){
	_displayTimestamp();
	std::cout << " index:" << this->_accountIndex << ";amount:" << this->_amount << ";closed" << std::endl;	
}

void	Account::makeDeposit(int deposit){
	_displayTimestamp();
	std::cout << " index:" << this->_accountIndex << ";p_amount:" << this->_amount << ";deposit:"<< deposit;
	this->_nbDeposits++;
	this->_amount += deposit;
	std::cout << ";amount:" << this->_amount << ";nb_deposits:" << this->_nbDeposits << std::endl;
	Account::_totalNbDeposits++;
	Account::_totalAmount += deposit;
	return ;
}

bool	Account::makeWithdrawal(int withdrawal){
	_displayTimestamp();
	std::cout << " index:" << this->_accountIndex << ";p_amount:" << this->_amount << ";withdrawal:";
	if (withdrawal > checkAmount())
	{
		std::cout << "refused" << std::endl;
		return (0);
	}
	this->_amount -= withdrawal;
	this->_nbWithdrawals++;
	std::cout << withdrawal << ";amount:" << this->_amount << ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
	Account::_totalAmount -= withdrawal;
	Account::_totalNbWithdrawals ++;
	return (1);
}

int	Account::checkAmount(void) const{
	return (this->_amount);
}

void	Account::displayStatus(void) const{
	_displayTimestamp();
	std::cout << " index:" << this->_accountIndex << ";amount:" << this->_amount << ";deposits:" << this->_nbDeposits << ";withdrawals:" << this->_nbWithdrawals << std::endl;
	return ;
}

void	Account::displayAccountsInfos(void) {
	_displayTimestamp();
	std::cout << " accounts:" << Account::_nbAccounts << ";amount:" << Account::_totalAmount<< ";deposits:" << Account::_totalNbDeposits << ";withdrawals:" << Account::_totalNbWithdrawals << std::endl;
}

int	Account::getNbAccounts(void){
	return (Account::_nbAccounts);
}

int	Account::getNbDeposits(void){
	return (Account::_totalNbDeposits);
}

int	Account::getNbWithdrawals(void){
	return (Account::_totalNbWithdrawals);
}

int	Account::getTotalAmount(void){
	return (_totalAmount);
}