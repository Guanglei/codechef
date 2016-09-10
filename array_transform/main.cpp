#include <iostream>
#include <vector>

int main()
{
    int T = 0;
    std::cin >> T;
    while(T--)
    {
        int n = 0, k = 0;
        std::cin >> n >> k;
        std::vector<int> numbers;
        while(n--)
        {
            int i = 0;
            std::cin >> i;
            numbers.push_back(i);
        }
        
        if(n == 0 || n == 1)
        {
            std::cout << "NO" << std::endl;
        }

        ++k;
        
        int base1 = numbers[0];
        int base2 = numbers[1];
        int odd_number1 = 0, odd_number2 = 0;
        for(auto i : numbers)
        {
            if(((i - base1) % k) != 0)
            {
                ++ odd_number1;
            }

            if(((i - base2) % k) != 0)
            {
                ++ odd_number2;
            }
        }

        if(odd_number1 == 0 || odd_number1 == 1 || odd_number2 == 0 || odd_number2 == 1)
        {
            std::cout << "YES" << std::endl;
        }
        else
        {
            std::cout << "NO" << std::endl;
        } 
    }

    return 0;
}
