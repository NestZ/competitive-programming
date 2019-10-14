#include<bits/stdc++.h>
using namespace std;

int main(){
      int n;cin >> n;
      for(int i = 0;i < n;i++){
            long long int x;cin >> x;
            long long  y;cin >> y;
            if(x - y > 1)cout << "YES\n";
            else cout << "NO\n"; 
      }
      return 0;
}