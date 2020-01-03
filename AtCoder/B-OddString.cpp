#include<bits/stdc++.h>
using namespace std;

int main(){
      string s;cin >> s;
      int n = s.length();
      for(int i = 1;i <= n;i += 2){
            cout << s[i - 1];
      }
}