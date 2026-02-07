/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mturgeon <maxime.p.turgeon@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 11:17:07 by mturgeon          #+#    #+#             */
/*   Updated: 2026/02/07 09:24:48 by mturgeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

//gives time in seconds since epoch
time_t  BitcoinExchange::convertDateToEpoch(std::string date)
{
	int year;
	int month;
	int days;

	date.erase(date.find_last_not_of(" \t\n\r\f\v") + 1);
	//format YYYY-MM-DD
	std::string::iterator   it = date.begin();
	std::string::iterator   temp;

	if (date.find_first_not_of("0123456789-") != std::string::npos)
		throw (std::runtime_error("wrong input"));
	while (*it != '-')
		it++;
	year = atoi(std::string(date.begin(), it).c_str());
	if (year < 1970 || year > this->_date->tm_year + 1900)
		throw (std::runtime_error("wrong input"));
	it++;
	temp = it;
	while (*it != '-')
		it++;
	month = atoi(std::string(temp, it).c_str());
	if (month < 1 || month > 12)
		throw (std::runtime_error("wrong input"));
	it++;
	temp = it;
	days = atoi(std::string(temp, date.end()).c_str());
	if (days < 1 || days > 31)
		throw (std::runtime_error("wrong input"));
	return ((year - 1970) * 31556926 + (month - 1) * 2629743 + (days - 1) * 86400);
}

//parse data.csv: before ',' -> convert to days since epoch; after -> atod in val
BitcoinExchange::BitcoinExchange(std::ifstream &data)
{
	std::time_t timestamp;

	std::time(&timestamp);
	this->_date = gmtime(&timestamp);

	std::string				buffer;
	std::string				temp;
	time_t					key;
	float					value;
	std::string::iterator	middle;

	//Checks for proper template and moves the "reading head" past the first line.
	getline(data, buffer);
	if (buffer != "date,exchange_rate")
		throw (std::runtime_error("bad data header"));

	while (getline(data, buffer)) 
	{
		middle = buffer.begin();
		for (std::string::iterator it = buffer.begin(); it != buffer.end(); it++)
		{
			if (*it == ',')
			{
				key = convertDateToEpoch(std::string(buffer.begin(), it));
				middle = it + 1;
			}
		}
		temp = std::string(middle, buffer.end());
		if (temp.find_first_not_of("0123456789.") != std::string::npos)
			throw (std::runtime_error("bad input"));
		value = atof(temp.c_str());

		//temp pair of an iterator to map and a boolreturned from insert.
		std::pair<std::map<time_t, float>::iterator, bool> res = this->_rates.insert(std::make_pair(key, value));
		//If key not unique, flag set to false.
		if (!res.second)
			throw (std::runtime_error("duplicate date in data"));
	}
}

//number based on line index of input.txt
void	printLineNum(void)
{
	static int num = 2;

	std::cout << "(" << num << "): ";
	num++;
	return ;
}

BitcoinExchange::~BitcoinExchange(void){}

void	BitcoinExchange::convert(std::ifstream &input)
{
	std::string	buffer;

	getline(input, buffer);
	if (buffer != "date | value")
		throw (std::runtime_error("bad logfile header"));

	time_t	date;
	std::string dateStr;
	float   value;
	while (getline(input, buffer))
	{
		printLineNum();
		std::string::iterator mid = buffer.begin() + buffer.find_first_of("|");
		if (buffer.find_first_of("|") == std::string::npos || distance(mid, buffer.end()) == 0)
		{
			std::cout << "Error: bad input => " << buffer << std::endl;
			continue; 
		}
		try
		{
			dateStr = std::string(buffer.begin(), mid);
			date = convertDateToEpoch(dateStr);
		}
		catch(const std::exception& e)
		{
			std::cout << "Error: bad input => " << buffer << std::endl;
			continue;
		}
		value = atof(std::string(mid + 1, buffer.end()).c_str()) * findRate(date);
		if (value > INT32_MAX)
		{
			std::cout << "Error: too large a number." << std::endl;
			continue;
		}
		if (value < 0)
		{
			std::cout << "Error: not a positive number." << std::endl;
			continue;
		}
		std::cout << dateStr.erase(dateStr.find_last_not_of(" \t\n\r\f\v") + 1) << " => " << findRate(date) << " = " <<  value << std::endl;
	}
	return ;
}

float   BitcoinExchange::findRate(time_t date)
{
	for (std::map<time_t, float>::const_reverse_iterator it = this->_rates.rbegin(); it != this->_rates.rend(); it++)
	{
		if (date >= it->first)
			return (it->second);
	}
	throw (std::runtime_error("no matching rate found !"));
}

//Mostly for debugging puproses.
void	BitcoinExchange::printData(void) const
{
	for(std::map<time_t, float>::const_iterator it = this->_rates.begin();
	it != this->_rates.end(); ++it)
	{
		std::cout << it->first << ", " << it->second << "\n";
	}
}