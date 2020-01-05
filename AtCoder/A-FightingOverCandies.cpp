#include<bits/stdc++.h>
using namespace std;
//size_t f = string::npos
//make pair, tuple

int main(){
      int arr[3];cin >> arr[0] >> arr[1] >> arr[2];
      sort(arr, arr + 3);
      if(arr[2] == arr[0] + arr[1])cout << "Yes";
      else cout << "No";
}