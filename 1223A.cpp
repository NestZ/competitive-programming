#include<bits/stdc++.h>
using namespace std;

int main(){
      int n;cin >> n;
      for(int i = 0;i < n;i++){
            int m;cin >> m;
            if(m < 4)cout << 4 - m << "\n";
            else cout << (m - 4) % 2 << "\n";
      }
      return 0;
}