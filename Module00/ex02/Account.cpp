/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fracurul <fracurul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 10:26:15 by fracurul          #+#    #+#             */
/*   Updated: 2025/07/09 12:45:08 by fracurul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

int	Account::getNbAccounts(void){
	return (_nbAccounts);
}

int	Account::getTotalAmount(void){
	return (_totalAmount);
}

int	Account::getNbDeposits(void){
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals( void ){
	return (_totalNbWithdrawals);
}

int	Account::checkAmount(void) const{
	return (_amount);
}

void	Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts()
			<< ";total:" << getTotalAmount()
			<< ";deposits" << getNbDeposits()
			<< ";withdrawals:" << getNbWithdrawals() << std::endl;
}

void	Account::_displayTimestamp(void)
{
	std::time_t	actual = std::time(NULL);
	std::tm		*local = std::localtime(&actual);
	

	std::cout << "["
	<< 1900 + local->tm_year
	<< std::setw(2) << std::setfill('0') << local->tm_mon + 1
	<< std::setw(2) << std::setfill('0') << local->tm_mday
	<< "_"
	<< std::setw(2) << std::setfill('0') << local->tm_hour
	<< std::setw(2) << std::setfill('0') << local->tm_min
	<< std::setw(2) << std::setfill('0') << local->tm_sec
	<< "] ";
}

void	Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
			<< ";p_amount:" << checkAmount()
			<< ";deposit:" << deposit;
	_amount += deposit;
	_totalAmount += deposit;
	_nbDeposits++;
	_totalNbDeposits++;
	std::cout << ";amount:" << checkAmount()
			<< ";nb_deposits:" <<_nbDeposits << std::endl;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
			<< ";p_amount:" << _amount
			<< ";withdrawal:";
	if (withdrawal > checkAmount())
	{
		std::cout << "refused" << std::endl;
		return (false);
	}
	_amount -= withdrawal;
	_totalAmount -= withdrawal;
	_nbWithdrawals++;
	_totalNbWithdrawals++;
	std::cout << withdrawal
			<< ";amount:" << checkAmount()
			<< ";nb_withdrawals:" << _nbWithdrawals << std::endl;
	return (true);
}

void	Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
			<< ";amount:" << checkAmount()
			<< ";deposits:" << _nbDeposits
			<< ";withdrawals:" << _nbWithdrawals << std::endl;
}

Account::Account(int initial_deposit)
{
	_accountIndex = _nbAccounts;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_nbAccounts++;
	_totalAmount += initial_deposit;

	_displayTimestamp();
	std::cout << "index:" << _accountIndex
			<< ";amount:" << checkAmount()
			<< ";created" << std::endl;
}

Account::~Account(void)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
			<< ";amount:" << checkAmount()
			<< ";closed" << std::endl;
	_nbAccounts--;
	_totalAmount -= _amount;
}