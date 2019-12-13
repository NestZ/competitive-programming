#include<bits/stdc++.h>
using namespace std;

int main(){
      string s1;cin >> s1;
      string s2;cin >> s2;
      string ans;
      int n = s1.length();
      for(int i = 0;i < n;i++){
            int d;
            if((int)tolower(s1[i]) <= 'a' + 8)d = ((int)(tolower(s1[i]) - 'a') + 1 + ('z' - tolower(s2[i]))) % 26;
            else d = (int)tolower(s1[i]) - (int)tolower(s2[i]);
            if(d < 10 && d >= 0)ans += to_string(d);
            else return cout << "R.I.P.", 0;
      }
      cout << ans;
}