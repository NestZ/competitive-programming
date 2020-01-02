#include<bits/stdc++.h>
using namespace std;

int sum(int x){
      int sum = 0;
      while(x > 0){
            sum += x % 10;
            x /= 10;
      }
      return sum;
}

int main(){
      int n,a,b;cin >> n >> a >> b;
      int ans = 0;
      for(int i = 1;i <= n;i++){
            int t = sum(i);
            if(t >= a && t <= b)ans += i;
      }
      cout << ans;
}