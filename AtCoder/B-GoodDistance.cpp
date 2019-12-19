#include<bits/stdc++.h>
using namespace std;

int main(){
      int n;cin >> n;
      int d;cin >> d;
      int arr[n + 10][d + 10];
      int ans = 0;
      for(int i = 0;i < n;i++){
            for(int j = 0;j < d;j++){
                  cin >> arr[i][j];
            }
      }
      for(int i = 0;i < n - 1;i++){
            for(int j = i + 1;j < n;j++){
                  int sum = 0;
                  for(int k = 0;k < d;k++){
                        sum += pow(arr[i][k] - arr[j][k], 2);
                  }
                  if(floor(sqrt(sum)) == ceil(sqrt(sum)))ans++;
            }
      }
      cout << ans;
}