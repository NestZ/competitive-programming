#include<bits/stdc++.h>
using namespace std;

int main(){
      int arr[3];
      int k;
      for(int i = 0;i < 3;i++)cin >> arr[i];
      cin >> k;
      int m = *max_element(arr, arr + 3);
      int n = m;
      for(int i = 0;i < k;i++)m *= 2;
      cout << arr[0] + arr[1] + arr[2] + m - n;
}