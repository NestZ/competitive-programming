#include<bits/stdc++.h>
using namespace std;
//size_t f = string::npos
//make pair, tuple

int main(){
      int curr = 0;
      int ans = 0;
      int n;cin >> n;
      string s;cin >> s;
      for(int i = 0;i < n;i++){
            if(s[i] == 'I')curr++;
            else curr--;
            ans = max(ans, curr);
      }
      cout << ans;
}