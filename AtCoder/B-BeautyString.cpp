#include<bits/stdc++.h>
using namespace std;
//size_t f = string::npos
//make pair, tuple

int main(){
      string s;cin >> s;
      map<char, int> m;
      int n = s.length();
      int ans = 0;
      for(int i = 0;i < n;i++){
            m[s[i]]++;
            if(m[s[i]] & 1)ans++;
            else ans--;
      }
      if(ans == 0)cout << "Yes";
      else cout << "No";
}