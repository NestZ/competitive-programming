#include<bits/stdc++.h>
using namespace std;

int main(){
      vector<int> arr;
      do{
            int t;
            cin >> t;
            arr.push_back(t);
      }while(arr.back() != -1);
      int a[30] = {1};
      int b[30] = {2};
      for(int i = 1;i < 30;i++){
            a[i] = b[i - 1];
            b[i] = b[i - 1] + a[i - 1] + 1;
      }
      for(int i = 0;i < arr.size() - 1;i++){
            cout << b[arr[i] - 1] << " " << a[arr[i] - 1] + b[arr[i] - 1] + 1 << "\n";
      }
      return 0;
}