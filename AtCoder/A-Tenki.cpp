#include<bits/stdc++.h>
using namespace std;

int main(){
      string s;cin >> s;
      string ss;cin >> ss;
      int ans = 0;
      for(int i = 0;i < 3;i++){
            if(ss[i] == s[i])ans++;
      }
      cout << ans;
}