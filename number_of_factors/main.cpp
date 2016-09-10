#include <iostream>
#include <vector>
#include <cstdint>
#include <unordered_map>

int main()
{
    int arr[1000];
    for(int i=2; i<1000; i++)
    {
        arr[i] = 1;
    }

    for(int i=2; i<1000; i++)
    {
        if(arr[i])
        {
            for(int j=i; j*i<1000; j++)
            {
                arr[j*i] = 0;
            }
        }
    }
    
    std::vector<int> primes;
    for(int i=2; i < 1000; i++)
    {
        if(arr[i])
        {
            primes.push_back(i);
        }
    }
    
    int t = 0;
    std::cin >> t;
    
    while(t--)
    {
        int n = 0;
        std::cin >> n;
        std::unordered_map<uint32_t, int> real_primes;
        while(n--)
        {
            int i = 0;
            std::cin >> i;
            for(int j = 0; j < primes.size(); ++j)
            {
                while(true)
                {
                    if(i % primes[j] == 0)
                    {
                        ++real_primes[j];
                        i /= primes[j];
                    }
                    else
                    {
                        break;
                    }
                }

                if(i == 1)
                {
                    break;
                }
            }
            
            if(i != 1)
            {
                ++real_primes[i];
            }
               
        }

        uint64_t ret = 0;

        for(auto& i : real_primes)
        {
            if(i.second > 0)
            {
               if(ret == 0)
               {
                   ret = i.second;
               }
               else
               {
                   ret = i.second + (i.second+1) * ret;
               }
            }
        }

        std::cout << (++ret) << std::endl;

    }
    return 0;
}
