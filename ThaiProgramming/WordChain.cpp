#include<bits/stdc++.h>
using namespace std;

int main(){
      int l;cin >> l;
      int n;cin >> n;
      string s;cin >> s;
      for(int i = 1;i < n;i++){
            string t;
            cin >> t;
            int f = 0;
            for(int j = 0;j < l;j++){
                  if(s[j] != t[j])f++;
            }
            if(f > 2)return cout << s, 0;
            else s = t;
      }
      cout << s;
      return 0;
}