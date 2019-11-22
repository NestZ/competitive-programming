#include<bits/stdc++.h>
using namespace std;

int main(){
      int n;cin >> n;
      for(int i = 0;i < n;i++){
            int a,b,c;cin >> a >> b >> c;
            int ans = min(b << 1,(c >> 1) << 1);
            b -= ans >> 1;
            ans += ans >> 1;
            ans += min(a << 1,(b >> 1) << 1) + (min(a << 1,(b >> 1) << 1) >> 1);
            cout << ans << "\n";
      }
      return 0;
}