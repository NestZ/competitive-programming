#include<bits/stdc++.h>
using namespace std;

int main(){
      string s;cin >> s;
      int n = s.length();
      map<char, int> m;
      int ans = 0;
      for(int i = 0;i < n;i++){
            m[s[i]]++;
            if(m[s[i]] == 2)ans--;
            else ans++;
      }
      if(ans == 0)cout << "Yes";
      else cout << "No";
}