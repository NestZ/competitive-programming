#include<bits/stdc++.h>
using namespace std;

int main(){
      int n;cin >> n;
      int arr[n] = {0};
      for(int i = 0;i < n;i++)cin >> arr[i];
      sort(arr,arr + n);
      int count = 0;
      for(int i = 0;i < n - 1;i++){
            if(arr[i] != 0){
                  for(int j = i + 1;j < n;j++){
                        if(arr[j] % arr[i] == 0 && arr[j] != 0)arr[j] = 0;
                  }
                  count++;
            }
      }
      if(arr[n - 1] != 0)count++;
      cout << count;
      return 0;
}