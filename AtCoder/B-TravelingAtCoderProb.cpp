#include<bits/stdc++.h>
using namespace std;
//size_t f = string::npos
//make pair, tuple

int main(){
      int n;cin >> n;
      int arr[n + 5];
      for(int i = 0;i < n;i++)cin >> arr[i];
      cout << *max_element(arr, arr + n) - *min_element(arr, arr + n);
}