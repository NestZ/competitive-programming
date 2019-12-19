#include<bits/stdc++.h>
using namespace std;

bool isOdd(int x){
      int ans = 0;
      while(x > 0){
            ans++;
            x /= 10;
      }
      return 1 & ans;
}

int main(){
      int n;cin >> n;
      int ans = 0;
      for(int i = 0;i <= n;i++){
            if(isOdd(i))ans++;
      }
      cout << ans;
}