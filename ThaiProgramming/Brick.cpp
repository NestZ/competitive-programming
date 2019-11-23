#include<bits/stdc++.h>
using namespace std;

int main(){
      int n,m;cin >> n >> m;
      char arr[n + 5][m + 5];
      int h[m + 5];for(int i = 0;i < m;i++)h[i] = n;
      for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                  cin >> arr[i][j];
                  if(arr[i][j] == 'O')h[j] = min(i, h[j]);
            }
      }
      for(int i = 0;i < m;i++){
            int t;cin >> t;
            for(int j = h[i] - 1;j >= h[i] - t && j >= 0;j--){
                  arr[j][i] = '#';
            }
      }
      for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                  cout << arr[i][j];
            }
            cout << "\n";
      }
      return 0;
}