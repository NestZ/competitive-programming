#include<bits/stdc++.h>
using namespace std;
//size_t f = string::npos
//make pair, tuple

int main(){
      int k,s;cin >> k >> s;
      int ans = 0;
      for(int i = 0;i <= k;i++){
            for(int j = 0;j <= k;j++){
                  int r = s - i - j;
                  if(r >= 0 && r <= k)ans++;
            }
      }
      cout << ans;
}