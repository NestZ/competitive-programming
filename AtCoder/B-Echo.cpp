#include<bits/stdc++.h>
using namespace std;

int main(){
      int n;cin >> n;
      string s;cin >> s;
      if(n & 1)return cout << "No", 0;
      for(int i = 0;i < n / 2;i++){
            if(s[i] != s[n / 2 + i])return cout << "No", 0;
      }
      cout << "Yes";
}