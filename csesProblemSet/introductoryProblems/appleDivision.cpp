#include<bits/stdc++.h>
#define ll long long int
using namespace std;

ll appleDivision(ll arr[], ll n, ll i, ll s1, ll s2)
{
  if(i == n)
    return abs(s1 - s2);
  
  ll left = appleDivision(arr, n, i+1, s1 + arr[i], s2);
  ll right = appleDivision(arr, n, i+1, s1, s2 + arr[i]);
  return min(left, right);
}

int main()
{
  ll n;
  cin>>n;
  ll arr[n];

  for(ll i=0;i<n;i++)
    cin>>arr[i];
  cout<<appleDivision(arr, n, 0, 0, 0);
  return 0;
}