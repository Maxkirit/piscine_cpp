/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mturgeon <maxime.p.turgeon@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 20:37:18 by mturgeon          #+#    #+#             */
/*   Updated: 2026/02/03 10:58:09 by mturgeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main(void)
{
    Array<int> a;
    int *b = new int();
    int *c = new int[0];
    Array<char>         testChar(5);
    Array<float>        testFloat(5);
    Array<std::string>  testString(5);
    Array< Array<int> >   testIntMtx(5);
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

    //build matrix w/ random numbers from 0 to 100
    std::srand(time(0));
    int select;
    for (int i = 0; i < 5; i++)
    {
        testFloat[i] = (float) rand() / (float) RAND_MAX;
        testChar[i] = 32 + (((float) rand() / (float) RAND_MAX) * 95);
        select = ((float) rand() / (float) RAND_MAX) * 100;
        testString[i] = words[select];
    }

    for (int i = 0; i < 5; i++)
    {
        testIntMtx[i] = Array<int>(5);
        for (int j = 0; j < 5; j++)
            testIntMtx[i].setValueAtIndex(((float) rand() / (float) RAND_MAX) * 100, j); 
    }

    try
    {
        std::cout << a[0] << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    std::cout << *b << std::endl;
    std::cout << c[0] << std::endl;

    std::cout << "~~~~~CHARACTERS~~~~~" << std::endl;
    std::cout << "char array: ";
    for (int i = 0; i < 5; i++)
    {
        std::cout << testChar[i] << ", "; 
    }
    std::cout << std::endl;

    std::cout << "~~~~~FLOATS~~~~~" << std::endl;
    std::cout << "float array: ";
    for (int i = 0; i < 5; i++)
    {
        std::cout << testFloat[i] << ", "; 
    }
    std::cout << std::endl;

    std::cout << "~~~~~STRINGS~~~~~" << std::endl;
    std::cout << "string array: ";
    for (int i = 0; i < 5; i++)
    {
        std::cout << testString[i] << ", "; 
    }
    std::cout << std::endl;

    std::cout << "~~~~~MATRIX~~~~~" << std::endl;
    for (int i = 0; i < 5; i++)
    {
        std::cout << "| ";
        for (int j = 0; j < 5; j++)
            std::cout << std::left << std::setw(3) << testIntMtx[i][j] << " ";
        std::cout << "|" << std::endl;
    }

    std::cout << "~~~~~~MODIFIED FLOATS~~~~~~" <<std::endl;
    for (int i = 0; i < 5; i++)
    {
        testFloat[i] = 0.5f;
    }
     for (int i = 0; i < 5; i++)
    {
        std::cout << testFloat[i] << " ";
    }
    std::cout << std::endl;
    
    std::cout << "~~~~~~SIZES~~~~~" << std::endl;
    std::cout << "size float: " << testFloat.size() << std::endl;
    std::cout << "size char: " << testChar.size() << std::endl;
    std::cout << "size string: " << testString.size() << std::endl;
    std::cout << "size one row of mtx: " << testIntMtx[0].size() << std::endl;
    delete b;
    delete [] c;
    return (0);

    // check if operator[] works with data types other than int (size_t, casted float, long long, etc)
}