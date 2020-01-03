#include<bits/stdc++.h>
using namespace std;

int main(){
      int n,m;cin >> n >> m;
      char arr[n + 5][m + 5];
      for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                  cin >> arr[i][j];
            }
      }
      for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                  if(arr[i][j] == '#')cout << '#';
                  else{
                        int ans = 0;
                        for(int k = i - 1;k <= i + 1;k++){
                              if(k >= 0 && k < n){
                                    for(int l = j - 1;l <= j + 1;l++){
                                          if(l >= 0 && l < m){
                                                if(arr[k][l] == '#')ans++;
                                          }
                                    }
                              }
                        }
                        cout << ans;
                  }
            }
            cout << "\n";
      }
}