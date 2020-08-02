#include<bits/stdc++.h>
using namespace std;

int main(){
      int n,m;cin >> n >> m;
      int l,k;cin >> l >> k;
      int c;cin >> c;
      int sum = 0;
      for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                  int t;cin >> t;
                  sum += t;
            }
      }
      cout << (sum + (l * k * c) + c - 1) / c;
      return 0;
}