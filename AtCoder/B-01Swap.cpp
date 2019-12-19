#include<bits/stdc++.h>
using namespace std;

int main(){
      int n;cin >> n;
      int arr[n + 10];
      int ans = 0;
      for(int i = 0;i < n;i++){
            cin >> arr[i];
            if(arr[i] != i + 1)ans++;
      }
      if(ans == 0 || ans == 2)cout << "YES";
      else cout << "NO";
}