#include <iostream>
#include <cmath>

void generate_prime(int start, int end)
{
  for(;start<=end;++start)
  {
    int root = std::sqrt(start);
    bool is_prime = true;
    for(int i = 2; i <= root; ++i)
    {
      if(start % i == 0)
      {
        is_prime = false;
        break;
      }
    }

    if(is_prime)
    {
      std::cout << start << std::endl;
    }
  }
}

int main()
{
  int line = 0;
  std::cin >> line;
  for(int i = 1; i<= line; ++i)
  {
    int start = 0, end = 0;
    std::cin >> start;
    std::cin >> end;

    if(end >= start)
    {
      generate_prime(start, end);
      if(i < line)
      {
        std::cout << std::endl;
      }
    }
    else
    {
      std::cout << std::endl;
    }
  }
  
  return 0;
}
