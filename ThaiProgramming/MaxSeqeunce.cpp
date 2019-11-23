#include<bits/stdc++.h>
using namespace std;

int main(){
      int n;cin >> n;
      int arr[n + 10];
      int Max = -1280;
      int a,b;
      for(int i = 0;i < n;i++)cin >> arr[i];
      for(int i = 0;i < n;i++){
            int sum = 0;
            for(int j = i;j < n;j++){
                  sum += arr[j];
                  if(sum > Max){
                        a = i;
                        b = j;
                        Max = sum;
                  }
            }
      }
      if(Max > 0){
            for(int i = a;i <= b;i++)cout << arr[i] << " ";
            cout << "\n" << Max;
      }
      else cout << "Empty sequence";
      return 0;
}