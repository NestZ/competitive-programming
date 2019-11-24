#include<bits/stdc++.h>
using namespace  std;

bool p(int a){
      string s = to_string(a);
      string s2 = "";
      for(int i = s.length() - 1;i >= 0;i--){
            s2 += s[i];
      }
      if(s2 == s)return true;
      return false;
}

bool prime(int n){  
    if(n <= 1)return false;
    if(n <= 3)return true;
    if(n % 2 == 0 || n % 3 == 0)return false;
    for(int i = 5;i * i <= n;i = i + 6)if(n % i == 0 || n % (i + 2) == 0)return false;
    return true;
}  

int main(){
      int n;cin >> n;
      while(!prime(n) || !p(n))n++;
      cout << n;
}