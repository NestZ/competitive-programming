#include<bits/stdc++.h>
using namespace std;

int main(){
      int n,k;cin >> n >> k;
      string a;cin >> a;
      string b;cin >> b;
      int ans = 0;
      size_t f = a.find(b, 0);
      while(f != string::npos){
            ans++;
            f = a.find(b, f + 1);
      }
      cout << ans;
}