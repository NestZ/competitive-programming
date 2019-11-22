#include<bits/stdc++.h>
using namespace std;

int main(){
      int n;
      cin >> n;
      for(int i = 0;i < n;i++){
            int temp,up = 0,down = 0,ans = 1;
            cin >> temp;
            int arr[temp];
            for(int j = 0;j < temp;j++){
                  cin >> arr[j];
                  if(arr[j] > temp || arr[j] < 1)ans = 0;
                  else if(j > 0 && arr[j] - arr[j - 1] == 1)up++;
                  else if(j > 0 && arr[j] - arr[j - 1] == -1)down++;
                  else if(j > 0 && abs(arr[j] - arr[j - 1]) != temp - 1)ans = 0;
            }
            if(ans && (down == 0 || up == 0))cout << "YES\n";
            else cout << "NO\n";
      }
      return 0;
}