#include<bits/stdc++.h>
using namespace std;

bool odd(int n){
      int ans = 0;
      for(int i = 1;i <= n;i += 2){
            if(n % i == 0)ans++;
      }
      return ans == 8;
}

int main(){
      int n;cin >> n;
      int ans = 0;
      for(int i = 1;i <= n;i++){
            if(odd(i))ans++;
      }
      cout << ans;
}