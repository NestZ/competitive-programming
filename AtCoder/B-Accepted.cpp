#include<bits/stdc++.h>
using namespace std;

int main(){
      string s;cin >> s;
      int n = s.length();
      if(s[0] != 'A')return cout << "WA", 0;
      if(s[1] == 'C' || s[n - 1] == 'C')return cout << "WA", 0;
      bool c = false;
      for(int i = 1;i < n;i++){
            if(i >= 2 && s[i] == 'C' && i < n - 1){
                  if(!c)c = true;
                  else return cout << "WA", 0;
            }
            if(s[i] != 'C' && s[i] != 'A'){
                  if(isupper(s[i]))return cout << "WA", 0;
            }
      }
      if(c)cout << "AC";
      else cout << "WA";
}