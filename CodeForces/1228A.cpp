#include<bits/stdc++.h>
using namespace std;

bool valid(int n){
      string s = to_string(n);
      for(int i = 0;i < s.length() - 1;i++){
            for(int j = i + 1;j < s.length();j++){
                  if(s[i] == s[j])return false;
            }
      }
      return true;
}

int main(){
      int l,r;cin >> l >> r;
      for(int i = l;i <= r;i++){
            if(valid(i)){
                  return cout << i, 0;
            }
      }
      cout << "-1";
      return 0;
}