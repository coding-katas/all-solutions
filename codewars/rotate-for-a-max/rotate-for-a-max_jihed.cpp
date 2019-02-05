#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class MaxRotate
{
public:
  static long long maxRot(long long n)
  {
      string str = to_string(n);
      vector<long long> vct;
      vct.push_back(n);
      for (int j = 0; j < str.size() ; j++)
      {
        for (int i = j; i < str.size() - 1; i++)
        {
          auto f = [](char &x, char &y) {
            char aux = x;
            x = y;
            y = aux;
          };
          f(str[i], str[i + 1]);
        }
        vct.push_back(stoll(str));
      }
  return *max_element(vct.begin(), vct.end());
  }
};

int main()
{
    
}
