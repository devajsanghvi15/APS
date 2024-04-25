//uses Binary Index Tree (Fenwick tree)

#include<bits/stdc++.h>
using namespace std;

void update(int n, long long int BIT[], int index, long long int x) {              //add x to BIT[index]
  for(; index <= n; index += (index & -index))
    BIT[index] += x;
}

void constructBIT(int n, long long int arr[], long long int BIT[]) {
  for(int i = 1; i <= n; i++)
    update(n, BIT, i, arr[i]);
}

long long int sum(long long int BIT[], int index) {
  long long int ans = 0;
  for(; index > 0; index -= (index & -index))
    ans += BIT[index];

  return ans;
}

int main() {
  int n, q;
  cin >> n >> q;
  long long int arr[n + 1] = {0};
  long long int BIT[n + 1] = {0};

  for(int i = 1; i <= n; i++)
    cin >> arr[i];
  
  constructBIT(n, arr, BIT);

  for(int i = 0; i < q; i++){
    int type, k, u;
    cin >> type >> k >> u;

    if(type == 1){
      update(n, BIT, k, u - arr[k]);
      arr[k] = u;
    }
    else {
      cout << sum(BIT, u) - sum(BIT, k - 1) << endl;
    }
  }

  return 0;
}
