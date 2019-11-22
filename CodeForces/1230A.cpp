#include<bits/stdc++.h>
using namespace std;

int main(){
      int arr[4]= {0};
      cin >> arr[0] >> arr[1] >> arr[2] >> arr[3];
      int sum = arr[0] + arr[1] + arr[2] + arr[3];
      sort(arr,arr + 4);
      if(sum - arr[3] == arr[3] || sum - (arr[3] + arr[0]) == arr[3] + arr[0])return cout << "YES", 0;
      cout << "NO";
      return 0;
}