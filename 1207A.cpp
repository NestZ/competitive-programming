#include<bits/stdc++.h>
using namespace std;

int main(){
      int n;
      cin >> n;
      for(int i = 0;i < n;i++){
            int b,p,f;
            cin >> b >> p >> f;
            int h,c;
            cin >> h >> c;
            b /= 2;
            int ans = 0;
            if(h > c){
                  ans += min(b,p)*h;
                  b = max(b - p,0);
                  ans += min(b,f)*c;
            }
            else{
                  ans += min(b,f)*c;
                  b = max(b - f,0);
                  ans += min(b,p)*h;
            }
            cout << ans << "\n";
      }
      return 0;
}