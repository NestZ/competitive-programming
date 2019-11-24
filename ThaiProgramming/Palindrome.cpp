#include<bits/stdc++.h>
using namespace std;

bool p(string s){
      string t = "";
      for(int i = s.length() - 1;i >= 0;i--){
            t += s[i];
      }
      if(t == s)return true;
      return false;
}

int main(){
      string s;cin >> s;
      for(int i = 0;i < s.length();i++){
            if(s[i] > 57)s[i] = toupper(s[i]);
      }
      if(p(s.substr(0, s.length() / 2)) && p(s.substr((s.length() + 1) / 2, s.length())))cout << "Double Palindrome";
      else if(p(s))cout << "Palindrome";
      else cout << "No";
}