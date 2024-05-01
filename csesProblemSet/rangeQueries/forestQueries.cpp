#include<bits/stdc++.h>
using namespace std;

void calculatePrefixArray(vector<vector<int>> &vec, int n) {
  for(int i=1;i<=n;i++) {
    for(int j=2;j<=n;j++) {
      vec[i][j] += vec[i][j-1]; 
    }
  }

  for(int i=2;i<=n;i++) {
    for(int j=1;j<=n;j++) {
      vec[i][j] += vec[i-1][j]; 
    }
  }
}

int main() {
  int n, q;
  cin>>n>>q;

  vector<vector<int>> vec(n+1, vector<int>(n+1, 0));    //row and col 0 as 0, 1 based indexing

  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      char c;
      cin>>c;
      if(c=='*')
        vec[i][j] = 1;
      else
        vec[i][j] = 0;
    }
  }

  calculatePrefixArray(vec, n);

  for(int i=0;i<q;i++) {
    int x1, x2, y1, y2;
    cin>>x1>>y1>>x2>>y2;        
    cout<<vec[x2][y2] - vec[x1-1][y2] -vec[x2][y1-1] + vec[x1-1][y1-1]<<endl;
  }

  return 0;
}