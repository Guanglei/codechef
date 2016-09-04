#include <iostream>
#include <cstdint>
#include <unordered_map>

uint32_t max_gold_coins(uint32_t n)
{
  static std::unordered_map<uint32_t, uint32_t> g_map;

  switch(n)
  {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
      return n;
    default:
      auto iter = g_map.find(n);
      if(iter != g_map.end())
      {
        return iter->second;
      }
      else
      {
        auto ret = max_gold_coins(n/2) + max_gold_coins(n/3) + max_gold_coins(n/4);
        if(ret <= n)
        {
          ret = n; 
        }
        g_map[n] = ret;
        return ret;
      }
  }
}

int main()
{
  while(std::cin.peek() != EOF)
  {
    if(std::isdigit(std::cin.peek()))
    {
      uint32_t input = 0;
      std::cin >> input;
      std::cout << max_gold_coins(input) << std::endl; 
    }
    else
    {
      std::cin.get();
    }
  }
  return 0;
}
