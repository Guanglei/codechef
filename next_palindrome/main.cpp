#include <cstdint>
#include <string>
#include <iostream>

void print(const std::string& str)
{
    auto length = str.length();

    for(int j = 0; j <= length; ++j)
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
}

void increment_higher_part(std::string& str)
{
    for(int j = (str.length()-1)/2; j >= 0; --j)
    {
        if(str[j] == '9')
        {
            str[j] = '0';
        }
        else
        {
            ++str[j];
            return;
        }
    }

    str = "1" + str;
    str[str.length() - 1] = '1';
}

int main()
{
    int n = 0;
    std::cin >> n;
    while(n--)
    {
        std::string str;
        std::cin >> str;

        auto length = str.length();

        char* hc = &str[length == 1 ? 0 : length/2 - 1];
        char* lc = &str[length == 1 ? 0 : (length + 1)/2];
        while(*lc && *hc)
        { 
            if(*hc > *lc)
            {
                print(str);
                break;
            }
            else if(*hc < *lc)
            {
                increment_higher_part(str); 
                print(str);
                break;
            }

            --hc;
            ++lc;
        }
        
        if(!(*lc))
        {
            increment_higher_part(str);   
            print(str);
        }
    }

    return 0;
}
