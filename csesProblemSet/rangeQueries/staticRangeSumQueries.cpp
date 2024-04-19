//uses prefix sum array

#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n, q;
  cin >> n >> q;
  long long int v[n + 1] = {0}, pre[n + 1] = {0};
  for (int i = 1; i <= n; i++)
  {
    cin >> v[i];
    pre[i] = v[i] + pre[i - 1];
  }
  for (int i = 0; i < q; i++)
  {
    int a, b;
    cin >> a >> b;
    cout << pre[b] - pre[a - 1] << endl;
  }
  return 0;
}