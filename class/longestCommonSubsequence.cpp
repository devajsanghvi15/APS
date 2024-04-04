#include<bits/stdc++.h>
using namespace std;

int longestCommonSubsequence(string s1, string s2) {     //returns the length of longest common subsequence between 2 strings
  int len1 = s1.length(), len2 = s2.length();
  int dp[len1+1][len2+1] = {};

  for(int i=1;i<=len1;i++) {
    for(int j=1;j<=len2;j++) {
      if(s1[i-1] == s2[j-1])
        dp[i][j] = dp[i-1][j-1] + 1;
      else
        dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
    }
  }
  return dp[len1][len2];
  return 0;
}

int main() {
  string s1, s2;
  cin>>s1>>s2;             //eg: s1="abcda", s2="bdabac"  longestCommonSubstring="bda" => 3

  cout<<longestCommonSubsequence(s1, s2);
  return 0;
}