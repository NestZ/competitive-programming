#include<bits/stdc++.h>
using namespace std;

int main(){
      int n;
      cin >> n;
      int arr[n];
      int y = 0;
      int no = 0;
      for(int i = 0;i < n;i++){
            cin >> arr[i];
            if(arr[i] % 2 == 0)y++;
            else no++;
      }
      cout << min(y,no);
      return 0;
}