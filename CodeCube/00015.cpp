#include<bits/stdc++.h>
using namespace std;

int main(){
      int n;cin >> n;
      if(n & 1){
            for(int i = 0;i < n;i++){
                  for(int j = 0;j < n;j++){
                        if(j - i >= 0 && j <= n - i - 1)cout << "*";
                        else if(j >= n - i - 1 && j <= i)cout << "*";
                        else cout << " ";
                  }
                  cout << "\n";
            }
      }
      else cout << "error";
}