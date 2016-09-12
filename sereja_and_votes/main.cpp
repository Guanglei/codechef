#include <iostream>
#include <vector>

int main()
{
  int t = 0;
  std::cin >> t;
  while(t--)
  {
    int n = 0;
    int n_zero = 0;
    std::cin >> n;
    //std::vector<int> numbers;
    uint32_t sum = 0;
    bool any_greater_than_100 = false;
    for(int i=1; i<=n; ++i)
    {
      int j = 0;
      std::cin >> j;
      if(j > 100)
      {
        any_greater_than_100 = true;
      }
      
      if(j == 0)
      {
        ++ n_zero;
      }

      sum += j;
      //numbers.push_back(i);
    }
    
    if(any_greater_than_100 || sum < 100)
    {
      std::cout << "NO" << std::endl;
    }
    else if(sum == 100)
    {
      std::cout << "YES" << std::endl;
    }
    else
    {
      uint32_t diff = sum - 100;
      std::cout << (diff < (n-n_zero) ? "YES" : "NO") << std::endl;
    }
  }

  return 0;
}
