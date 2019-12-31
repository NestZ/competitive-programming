#include<bits/stdc++.h>
using namespace std;

bool isPa(int x){
      string s = to_string(x);
      int n = s.length();
      for(int i = 0;i < n / 2;i++){
            if(s[i] != s[n - i - 1])return false;
      }
      return true;
}

int main(){
      int a,b;cin >> a >> b;
      int ans = 0;
      for(int i = a;i <= b;i++){
            if(isPa(i))ans++;
      }
      cout << ans;
}