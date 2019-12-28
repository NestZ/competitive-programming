#include<bits/stdc++.h>
using namespace std;

int main(){
      string s;cin >> s;
      string t;cin >> t;
      int n = s.length();
      int i = 0;
      while(i < n){
            if(s == t)return cout << "Yes", 0;
            char temp = s[n - 1];
            string temp2 = s.substr(0, n - 1);
            s = temp + temp2;
            i++;
      }
      cout << "No";
}