#include<bits/stdc++.h>
using namespace std;

int main()
{
  long long int n, num, sum = 0;
  cin>>n;
  for(int i=1;i<n;i++)
  {
    cin>>num;
    sum += num;
  }
  cout<<(n*(n+1))/2 - (sum);
  return 0;
}