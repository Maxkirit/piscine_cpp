/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mturgeon <maxime.p.turgeon@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 11:16:17 by mturgeon          #+#    #+#             */
/*   Updated: 2026/02/05 18:06:06 by mturgeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string>
#include <sstream>
#include <map>
#include <ctime>
#include <fstream>
#include <cstdlib>


class BitcoinExchange
{
	private:
		std::map<time_t, float>	_rates;
		struct tm               *_date;

		BitcoinExchange(void);
		BitcoinExchange(BitcoinExchange const &src);
		BitcoinExchange	&operator=(BitcoinExchange const &rhs);

		time_t		convertDateToEpoch(std::string date);
		float		findRate(time_t date);

	public:
		BitcoinExchange(std::ifstream &data);
		~BitcoinExchange(void);

		void	convert(std::ifstream &input);

		void	printData(void) const;
};


#endif