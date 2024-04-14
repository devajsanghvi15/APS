#include<bits/stdc++.h>
using namespace std;

vector<string> grayCode(int n)
{
  if(n==1)
  {
    vector<string> s = {"0", "1"};
    return s;
  }
  vector<string> newArr = grayCode(n-1);
  for(int i=(pow(2, n)-1)/2;i>=0;i--)
  {
    newArr.push_back(newArr[i]);
  }
  for(int i=0;i<pow(2, n)/2;i++)
  {
    newArr[i] += "0";
  }
  for(int i=pow(2, n)/2;i<pow(2, n);i++)
  {
    newArr[i] += "1";
  }
  return newArr;
}

int main()
{
  int n;
  cin>>n;
  vector<string> newArr = grayCode(n);
  for(auto i=newArr.begin();i!=newArr.end();i++)
    cout<<*i<<"\n";
  return 0;
}