#include<bits/stdc++.h>
using namespace std;

int main(){
      int n;cin >> n;
      string s;cin >> s;
      int ans = INT_MIN;
      if(n == 2 && s[0] != s[1])return cout << 0, 0;
      else if(n == 2) return cout << 1, 0;
      for(int i = 1;i < n - 1;i++){
            set<char> s1;
            set<char> s2;
            set<char> s3;
            for(int j = 0;j < n;j++){
                  if(j < i)s1.insert(s[j]);
                  else{
                        if(s1.count(s[j]) != 0 && s3.count(s[j]) == 0){
                              s2.insert(s[j]);
                              s3.insert(s[j]);
                        }
                  }
            }
            ans = max(ans, (int)s2.size());
      }
      cout << ans;
}