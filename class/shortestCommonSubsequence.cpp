#include<bits/stdc++.h>
using namespace std;

int shortestCommonSubsequence(string s1, string s2) {  //returns the length of the SCS
  int len1 = s1.length(), len2 = s2.length();
  int dp[len1+1][len2+1] = {};

  for(int i=0;i<=len2;i++)              //init row 0 as 0 1 2 3 ...
    dp[0][i] = i;
  
  for(int i=0;i<=len1;i++)               //init col 0 as 0 1 2 3 ...
    dp[i][0] = i;

  for(int i=1;i<=len1;i++) {
    for(int j=1;j<=len2;j++) {
      if(s1[i-1] == s2[j-1])
        dp[i][j] = dp[i-1][j-1] + 1;
      else
        dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + 1;
    }
  }

  return dp[len1][len2];
}

int main() {
  string s1, s2;
  cin>>s1>>s2;             

  /*eg: s1="apqrstu", s2="kplrmntuo"  shortestCommonSubstring="akpqlrsmntuo" => 12 it is the shortest string which has both s1 and s2 as its subsequence*/

  cout<<shortestCommonSubsequence(s1, s2);
  return 0;
}