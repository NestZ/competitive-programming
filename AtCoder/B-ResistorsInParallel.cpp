#include<bits/stdc++.h>
using namespace std;

int main(){
      int n;cin >> n;
      double ans = 0;
      for(int i = 0;i < n;i++){
            int t;cin >> t;
            ans += 1.0 / t;
      }
      printf("%.6f", 1.0 / ans);
}