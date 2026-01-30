/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mturgeon <maxime.p.turgeon@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 14:45:45 by mturgeon          #+#    #+#             */
/*   Updated: 2026/01/30 15:20:43 by mturgeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP

class Data
{
    private:
        int _val;

    public:
        Data(void);
        Data(int val);
        Data(Data const &src);
        ~Data(void);
        Data    &operator=(Data const &rhs);

        int const   &getVal(void) const;
        void        setVal(int newVal);
};

#endif