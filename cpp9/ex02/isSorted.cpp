#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
        return (1);
    std::ifstream   in(argv[1]);
    std::string     buffer;
    int a;
    int b;

    in >> buffer;
    a = atoi(buffer.c_str());
    while (in >> buffer)
    {
        b = a;
        a = atoi(buffer.c_str());
        if (b > a)
        {
            std::cout << "unsorted, n -1 =  " << b << ", n = " << a << "\n";
            return (1);
        }
    }
    std::cout <<"sorted";
    return (0);
}