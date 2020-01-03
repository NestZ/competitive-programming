#include<bits/stdc++.h>
using namespace std;
//size_t f = string::npos
//make pair, tuple

int main(){
      string s;cin >> s;
      int ans = 0;
      int n = s.length();
      for(int i = 2;i < n;i += 2){
            if(s.substr(0, i / 2) == s.substr(i / 2,i / 2))ans = i;
      }
      cout << ans;
}