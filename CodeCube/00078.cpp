#include<bits/stdc++.h>
using namespace std;

int main(){
      int x;cin >> x;
      int sum = 0;
      int arr[7];
      set<int> s;
      for(int i = 0;i < 5;i++){
            cin >> arr[i];
            sum += arr[i];
            s.insert(arr[i]);
      }
      int w = sum - x;
      if(s.count(w) == 0 && w != 0)return cout << -1, 0;
      bool flag = true;
      for(int i = 0;i < 5;i++){
            if(flag && (arr[i] == w)){
                  arr[i] = 0;
                  flag = false;
            }
            cout << arr[i] << " ";
      }
}