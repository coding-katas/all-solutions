// Author : MKAOUAR Sonia SOFRECOM <sonia.mkaouar@sofrecom.com>
#include <vector>
#include <string>
#include <iostream>
#include <stdexcept>

class MaxRotate
{
public:
static std::vector<long long> m_tmp;
  static std::string getString(std::string schaine, int ipos)
  {
    std::string stmp;
    for (int i = 0; i < schaine.size(); ++i)
    {
      if (i != ipos)
        stmp += schaine[i];

    }
    return stmp;

  }

public:
  static long long maxRotationNum(std::vector<long long> tNumberVect)
  {
    long long iMax = tNumberVect[0];
    for (int i = 1; i < tNumberVect.size(); ++i)
    {
      if (tNumberVect[i] > iMax)
        iMax = tNumberVect[i];
    }
    return iMax;
  }

  static long long maxRot(long long n)
  {
    std::vector<long long> tmpVect;
    tmpVect.push_back(n);
    std::string sNumber = std::to_string(n);
    std::string stmp;
   for (int i=0; i < sNumber.size(); ++i)
    {
      try
      {
        char c = sNumber[i];
        
        stmp = getString(sNumber, i) + c;
        tmpVect.push_back(std::stoll(stmp));
        sNumber = stmp;
      }
      catch (const std::invalid_argument& ia) {
         std::cout << ia.what() << std::endl, 1;
      }
      catch (const std::out_of_range& oor) {
         std::cout << oor.what() << std::endl, 2;
      }
    }

    return maxRotationNum(tmpVect);
  }
};

int main()
{
  std::cout << MaxRotate::maxRot(38458215) << std::endl;
  return 0;
}
