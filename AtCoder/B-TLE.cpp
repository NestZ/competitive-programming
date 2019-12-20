#include<bits/stdc++.h>
using namespace std;

int main(){
      int n,t;cin >> n >> t;
      int ans = INT_MAX;
      bool flag = false;
      for(int i = 0;i < n;i++){
            int c,ti;cin >> c >> ti;
            if(ti <= t && c < ans){
                  ans = c;
                  flag = true;
            }
      }
      if(flag)cout << ans;
      else cout << "TLE";
}