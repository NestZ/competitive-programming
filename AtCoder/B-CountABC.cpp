#include<bits/stdc++.h>
using namespace std;
//size_t f = string::npos
//make pair, tuple

int main(){
      int n;cin >> n;
      string s;cin >> s;
      int ans = 0;
      size_t f = s.find("ABC", 0);
      while(f != string::npos){
            ans++;
            f = s.find("ABC", f + 1);
      }
      cout << ans;
}