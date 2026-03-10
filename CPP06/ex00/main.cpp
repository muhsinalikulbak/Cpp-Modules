
#include <cmath>
#include <iostream> 
#include <math.h>
#include <stdio.h>
#include <string>

int main()
{
    char* end = NULL;
    std::string str = "inf";
    double num = strtod(str.c_str(), &end);

    if (isinf(num))
        std::cout << "selam" << std::endl;
    
    std::string s = end;
    std::cout << s << std::endl;
    if (s[0] == '\0')
        std::cout << "a" << std::endl;
} 