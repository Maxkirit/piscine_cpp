/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mturgeon <maxime.p.turgeon@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 15:10:07 by mturgeon          #+#    #+#             */
/*   Updated: 2026/02/03 10:54:46 by mturgeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

template <typename T>
void    add10(T &num)
{
    num += 10;
    return ;
}
template<>
void    add10(char &num)
{
    if (num < 117)
        num += 10;
    return ;
}

void    switchString(std::string &str)
{
    for (size_t i = 0; i < str.length(); i++)
        add10(str[i]);
    return ;
}

template<typename T>
void    print(T const &elem)
{
    std::cout << "print elem: "<< elem << std::endl;
}

int main(void)
{
    int         tab0[10];
    float       tab1[10];
    char        tab2[10];
    std::string tab3[10];
    std::string words[100] = {
        "apple", "brave", "cloud", "dance", "eagle", "flame", "grape", "heart", "image", "juice",
        "knife", "lemon", "melon", "night", "ocean", "paper", "queen", "river", "stone", "table",
        "uncle", "voice", "water", "xenon", "yacht", "zebra", "acorn", "bread", "candy", "dream",
        "earth", "frost", "glass", "house", "index", "joker", "koala", "light", "mouse", "nurse",
        "olive", "piano", "quiet", "radio", "snake", "tiger", "under", "vivid", "whale", "x-ray",
        "youth", "zesty", "alarm", "brick", "chair", "daisy", "elbow", "field", "giant", "horse",
        "irony", "jelly", "kiosk", "lunar", "magic", "noble", "onion", "pearl", "query", "robot",
        "sugar", "tulip", "urban", "vocal", "watch", "yummy", "zones", "amber", "birth", "coast",
        "drift", "event", "fruit", "green", "hotel", "input", "joint", "kites", "layer", "music",
        "north", "outer", "patch", "quilt", "rough", "solid", "track", "ultra", "visit", "world"
    };

    //initializes the rand seed base on runtime timestamp
    std::srand(time(0));

    for (int i = 0; i < 10; i++)
    {
        tab0[i] = ((float) rand() / (float) RAND_MAX) * 100;
        tab1[i] = (float) rand() / (float) RAND_MAX;
        tab2[i] = 32 + (((float) rand() / (float) RAND_MAX) * 95);
        tab3[i] = words[tab0[i]];
    }

    int const           intConst[3] = {9, 101, 132};
    float const         floatConst[3] = {0.5684f, 87.546f, 4.24f};
    char const          charConst[3] = {'{', 'Z', 'z'};
    std::string const   stringConst[3] = {"balbalba", "oulala", "dayum son"};

    std::cout << "~~~~~BEFORE TRANSFORMATION~~~~~" << std::endl;
    std::cout << "ints:" << std::endl;
    for (int i = 0; i < 10; i++)
    {
        std::cout << "tab0[" << i << "]: '" << tab0[i] << "'" << std::endl; 
    }
    std::cout << "floats:" << std::endl;
    for (int i = 0; i < 10; i++)
    {
        std::cout << "tab1[" << i << "]: '" << tab1[i] << "'" << std::endl; 
    }
    std::cout << "char:" << std::endl;
    for (int i = 0; i < 10; i++)
    {
        std::cout << "tab2[" << i << "]: '" << tab2[i] << "'" << std::endl; 
    }
    std::cout << "string:" << std::endl;
    for (int i = 0; i < 10; i++)
    {
        std::cout << "tab3[" << i << "]: '" << tab3[i] << "'" << std::endl; 
    }

    iter(tab0, 10, add10);
    iter(tab1, 10, add10);
    iter(tab2, 10, add10);
    iter(tab3, 10, switchString);   

    std::cout << "~~~~~AFTER TRANSFORMATION (non const)~~~~~" << std::endl;
    std::cout << "ints:" << std::endl;
    for (int i = 0; i < 10; i++)
    {
        std::cout << "tab0[" << i << "]: '" << tab0[i] << "'" << std::endl; 
    }
    std::cout << "floats:" << std::endl;
    for (int i = 0; i < 10; i++)
    {
        std::cout << "tab1[" << i << "]: '" << tab1[i] << "'" << std::endl; 
    }
    std::cout << "char:" << std::endl;
    for (int i = 0; i < 10; i++)
    {
        std::cout << "tab2[" << i << "]: '" << tab2[i] << "'" << std::endl; 
    }
    std::cout << "string:" << std::endl;
    for (int i = 0; i < 10; i++)
    {
        std::cout << "tab3[" << i << "]: '" << tab3[i] << "'" << std::endl; 
    }
    
    std::cout << "~~~~~BEFORE TRANSFORMATION FOR CONST~~~~~" << std::endl;
    for (int i = 0; i < 3; i++)
    {
        std::cout << "intConst[" << i << "]: '" << intConst[i] << "'" << std::endl; 
    }
    std::cout << "floats:" << std::endl;
    for (int i = 0; i < 3; i++)
    {
        std::cout << "floatConst[" << i << "]: '" << floatConst[i] << "'" << std::endl; 
    }
    std::cout << "char:" << std::endl;
    for (int i = 0; i < 3; i++)
    {
        std::cout << "charConst[" << i << "]: '" << charConst[i] << "'" << std::endl; 
    }
    std::cout << "string:" << std::endl;
    for (int i = 0; i < 3; i++)
    {
        std::cout << "stringConst[" << i << "]: '" << stringConst[i] << "'" << std::endl; 
    }

    iter(intConst, 3, print);
    iter(floatConst, 3, print);
    iter(charConst, 3, print);
    iter(stringConst, 3, print);

    std::cout << "~~~~~AFTER TRANSFORMATION FOR CONST~~~~~" << std::endl;
    for (int i = 0; i < 3; i++)
    {
        std::cout << "intConst[" << i << "]: '" << intConst[i] << "'" << std::endl; 
    }
    std::cout << "floats:" << std::endl;
    for (int i = 0; i < 3; i++)
    {
        std::cout << "floatConst[" << i << "]: '" << floatConst[i] << "'" << std::endl; 
    }
    std::cout << "char:" << std::endl;
    for (int i = 0; i < 3; i++)
    {
        std::cout << "charConst[" << i << "]: '" << charConst[i] << "'" << std::endl; 
    }
    std::cout << "string:" << std::endl;
    for (int i = 0; i < 3; i++)
    {
        std::cout << "stringConst[" << i << "]: '" << stringConst[i] << "'" << std::endl; 
    }

    return (0);
}