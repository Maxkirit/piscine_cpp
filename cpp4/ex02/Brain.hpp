/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mturgeon <maxime.p.turgeon@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 10:41:39 by mturgeon          #+#    #+#             */
/*   Updated: 2026/01/26 11:34:03 by mturgeon         ###   ########.fr       */
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
        Brain(std::string idea);
        Brain(Brain const &src);
        ~Brain(void);

        Brain   &operator=(Brain const &rhs);

        std::string const &getIdea(void) const;
        void        setIdea(std::string newIdea);
        
    private:
        std::string _idea;
};

#endif