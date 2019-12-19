#include<bits/stdc++.h>
using namespace std;

int main(){
      int n;cin >> n;
      int k;cin >> k;
      string s;cin >> s;
      int t = s.length();
      for(int i = 0;i < t;i++){
            if(i + 1 == k)s[i] = tolower(s[i]);
      }
      cout << s;
}