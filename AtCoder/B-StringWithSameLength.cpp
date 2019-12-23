#include<bits/stdc++.h>
using namespace std;

int main(){
      int n;cin >> n;
      string a,b;cin >> a >> b;
      string ans = "";
      for(int i = 0;i < n;i++){
            ans += a[i];
            ans += b[i];
      }
      cout << ans;
}