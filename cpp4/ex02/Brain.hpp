/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mturgeon <maxime.p.turgeon@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 10:41:39 by mturgeon          #+#    #+#             */
/*   Updated: 2026/01/27 11:12:19 by mturgeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>
#include <string>

class Brain
{
	public:
		Brain(void);
		Brain(Brain const &src);
		~Brain(void);

		Brain   &operator=(Brain const &rhs);

		std::string const	&getIdea(unsigned int idx) const;
		void        		setIdea(std::string newIdea, unsigned int idx);
		
	private:
		std::string		_idea[100];
};

#endif