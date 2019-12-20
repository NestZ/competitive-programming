#include<bits/stdc++.h>
using namespace std;

int main(){
      int arr[5];
      int minn = INT_MAX;
      for(int i = 0;i < 5;i++){
            cin >> arr[i];
            if(arr[i] < minn)minn = arr[i];
      }
      int k;cin >> k;
      for(int i = 0;i < 5;i++){
            if(arr[i] - minn > k)return cout << ":(", 0;
      }
      cout << "Yay!";
}