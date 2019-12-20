#include<bits/stdc++.h>
using namespace std;

int main(){
      int n;cin >> n;
      double ans = 0;
      for(int i = 0;i < n;i++){
            double t;cin >> t;
            string s;cin >> s;
            if(s == "JPY")ans += t;
            else ans += t * 380000;
      }
      cout << ans;
}