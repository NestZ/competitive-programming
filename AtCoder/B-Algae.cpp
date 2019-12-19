#include<bits/stdc++.h>
using namespace std;

int main(){
      int r;cin >> r;
      int d;cin >> d;
      int x;cin >> x;
      for(int i = 0;i < 10;i++){
            x = (x * r) - d;
            cout << x << "\n";
      }
}