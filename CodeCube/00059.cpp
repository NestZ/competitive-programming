#include<bits/stdc++.h>
using namespace std;

int main(){
      int n,m;cin >> n >> m;
      int curr = 0;
      for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                  cout << (char)('A' + (curr % 26));
                  curr++;
            }
            cout << "\n";
      }
}