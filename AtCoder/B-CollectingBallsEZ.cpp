#include<bits/stdc++.h>
using namespace std;

int main(){
      int n,k;cin >> n >> k;
      int ans = 0;
      for(int i = 0;i < n;i++){
            int t;cin >> t;
            ans += min(t * 2,abs(t - k) * 2);
      }
      cout << ans;
}