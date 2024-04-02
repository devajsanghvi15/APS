#include<iostream>
using namespace std;
 
void weirdAlgorithm(int N)
{
  long long int n = (long long int)N;
  while(n!=1)
  {
    cout<<n<<" ";
    if(n%2 == 0)
      n = n >> 1;
    else
      n = (n*3) + 1;
  }
  cout<<n;
}
 
int main()
{
  int n;
  cin>>n;
  weirdAlgorithm(n);
  return 0;
}