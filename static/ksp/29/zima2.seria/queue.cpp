// constructing priority queues
#include <iostream>
#include <queue>
using namespace std;


  mycomparison(const bool& revparam=false)
    {reverse=revparam;}

  bool operator() (const int& lhs, const int&rhs) const
  {
    if (reverse) return (lhs>rhs);
    else return (lhs<rhs);
  }

int main ()
{


  // using mycomparison:
  priority_queue< int, vector<int>, mycomparison > fourth;



  return 0;
}
