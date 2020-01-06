#include<bits/stdc++.h>
using namespace std;
//size_t f = string::npos
//make pair, tuple

int main(){
      string s;cin >> s;
      int n = s.length();
      string ans = "";
      for(int i = 0;i < n;i++){
            if(s[i] == 'B' && ans.length() > 0)ans.pop_back();
            else if(s[i] != 'B')ans += s[i];
      }
      cout << ans;
}