#include<bits/stdc++.h>
using namespace std;

int main(){
      int n;cin >> n;
      for(int i = 0;i < n;i++){
            for(int j = 0;j < n;j++){
                  if(i <= n / 2){
                        if(j >= (n / 2) - i && j <= (n / 2) + i)cout << "*";
                        else cout << "-";
                  }
                  else{
                        if(j >= (n / 2) - (n - i - 1) && j <= (n / 2) + (n - i - 1))cout << "*";
                        else cout << "-";
                  }
            }
            cout << "\n";
      }
}
