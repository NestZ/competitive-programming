#include<bits/stdc++.h>
using namespace std;

int main(){
      string s;cin >> s;
      for(int i = 1;i < 4;i++){
            if(s[i] == s[i - 1])return cout << "Bad", 0;
      }
      cout << "Good";
}