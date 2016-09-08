#include <cstdint>
#include <string>
#include <iostream>

int main()
{
    std::string str;
    std::cin >> str;
    
    auto length = str.length();
    if(length == 0)
    {
        return 0;
    }

    if(length == 1)
    {
        if(str[0] == '9')
        {
            std::cout << 11 << std::endl;
        }
        else
        {
            std::cout << ((atoi(str.c_str())) + 1) << std::endl;
        }

        return 0;
    }


    auto low_c_index = &str[(length + 1)/2];
    auto high_c_index = &str[length/2 - 1];
    
    auto check_length = length/2;
    char *hc = nullptr, *lc = nullptr;

    for(int i=0; i < check_length; ++i)
    { 
        hc = high_c_index--;
        lc = low_c_index++;
        if(*hc > *lc)
        {
            for(int j = 0; j < length; ++j)
            {
                if(j <= (length/2 - 1))
                {
                    std::cout << str[j];
                }
                else if(j >= (length+1)/2)
                {
                    std::cout << str[length - j - 1];
                }
                else
                {
                    std::cout << str[j];
                }
            }

            std::cout << std::endl;

            return 0;
        }
        else if(*hc < *lc)
        {
            if(length % 2 != 0)
            {
                if(str[])
            }
            break;
        }
    }
    
    std::cout << "high_c_index is equal or lower than the low_c_index really need to figure out the next one" << std::endl;

    return 0;
}
