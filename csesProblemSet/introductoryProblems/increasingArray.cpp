#include<bits/stdc++.h>
using namespace std;

int main()
{
  vector<int> v;
  int n, element;
  cin>>n;
  for(int i=0;i<n;i++)
  {
    cin>>element;
    v.push_back(element);
  }
  long long count = 0;
  for(int i=1;i<n;i++)
  {
    if(v[i] < v[i-1])
    {
      count += (v[i-1] - v[i]);
      v[i] += (v[i-1] - v[i]);
    }
  }
  cout<<count;

  return 0;
}