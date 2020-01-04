#include<bits/stdc++.h>
using namespace std;
//size_t f = string::npos
//make pair, tuple

int main(){
      string o,e;cin >> o >> e;
      string ans = "";
      int n = min(o.length(), e.length());
      for(int i = 0;i < n;i++){
            ans += o[i];
            ans += e[i];
      }
      if(o.length() > e.length())ans += o[o.length() - 1];
      cout << ans;
}