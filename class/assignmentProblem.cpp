#include<bits/stdc++.h>
using namespace std;

bool isBitJSetInMask(int j, int mask)          //checks if bit j is set in mask
{
  return ((mask & (1<<j)) == (1<<j));
}

int assign(vector<vector<int>> &cost, int n)    //returns minimum cost 
{
  vector<int> dp(pow(2, n), INT_MAX);           //initialize array with infinity
  dp[0] = 0;

  for(int mask=0;mask<pow(2,n);mask++)         //iterate through all masks
  {
    int x = __builtin_popcount(mask);
    for(int j=0;j<n;j++)                        //iterate through jobs to find optimal
    {
      if(!isBitJSetInMask(j, mask))
      {
        dp[mask | (1<<j)] = min(dp[mask | 1<<j], dp[mask] + cost[x][j]);
      }
    }
  }
  return dp[pow(2, n) - 1];
}

int main()
{
  int n = 3;
  vector<vector<int>> cost= { {3, 2, 7},          //cost for person(i) in job(i)
                              {5, 1, 3},         //task is to minimize cost, 1 job 1 person
                              {2, 7 , 2} };
  cout<<assign(cost, n);
  return 0;
}