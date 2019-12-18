#include<bits/stdc++.h>
using namespace std;

int main(){
      int n;cin >> n;
      string s;cin >> s;
      int t = s.length();
      for(int i = 0;i < t;i++){
            s[i] = 'A' + (s[i] - 'A' + n) % 26;
      }
      cout << s;
}