#include<bits/stdc++.h>
using namespace std;

int main(){
      int n,t;cin >> n >> t;
      string a;cin >> a;
      string b;cin >> b;
      size_t f;
      f = a.find(b, 0);
      int ans = 0;
      while(f != string::npos){
            ans++;
            f = a.find(b, f + 1);
      }
      cout << ans;
}