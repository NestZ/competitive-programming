#include<bits/stdc++.h>
using namespace std;

int main(){
      int n;
      cin >> n;
      int arr[11];
      for(int i = 0;i < 11;i++)arr[i] = 0;
      for(int i = 0;i < n;i++){
            char c;
            cin >> c;
            if(c == 'L'){
                  for(int j = 0;j < 10;j++){
                        if(arr[j] == 0){
                              arr[j] = 1;
                              break;
                        }
                  }
            }
            else if(c == 'R'){
                  for(int j = 9;j >= 0;j--){
                        if(arr[j] == 0){
                              arr[j] = 1;
                              break;
                        }
                  }
            }
            else{
                  string s = "";s += c;
                  int num = stoi(s);
                  arr[num] = 0;
            }
      }
      for(int i = 0;i < 10;i++)cout << arr[i];
      return 0;
}
