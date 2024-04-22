//uses segment tree

#include<bits/stdc++.h>
using namespace std;

void constructSegTree(int input[], int segTree[], int index, int low, int high) {
  if(low==high) {
    segTree[index] = input[low];
    return;
  }

  int mid = (low+high)/2;
  constructSegTree(input, segTree, 2*index+1, low, mid);
  constructSegTree(input, segTree, 2*index+2, mid+1, high);
  segTree[index] = min(segTree[2*index+1], segTree[2*index+2]);
}

int query(int segTree[], int index, int low, int high, int a, int b) {
  if(low>=a && high<=b)
    return segTree[index];
  
  if(high<a || low>b)
    return INT_MAX;

  int mid = (low+high)/2;
  int left = query(segTree, 2*index+1, low, mid, a, b);
  int right = query(segTree, 2*index+2, mid+1, high, a, b);
  return min(left, right);
}

int main() {
  int n, q;
  cin>>n>>q;
  int input[n] = {0}, segTree[4*n] = {0};

  for(int i=0;i<n;i++)
    cin>>input[i];

  constructSegTree(input, segTree, 0, 0, n-1);

  for(int i=0;i<q;i++) {
    int a, b;
    cin>>a>>b;

    cout<<query(segTree, 0, 0, n-1, a-1, b-1)<<endl;
  }

  return 0;
}