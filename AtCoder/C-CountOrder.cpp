#include<bits/stdc++.h>
using namespace std;
//size_t f = string::npos
//make pair, tuple

int main(){
      int a = -1;
      int b = -1;
      int n;cin >> n;
      int arr[n + 5];
      int arrp[n + 5];
      int arrq[n + 5];
      int c = 1;
      for(int i = 0;i < n;i++)cin >> arrp[i];
      for(int i = 0;i < n;i++)cin >> arrq[i];
      for(int i = 0;i < n;i++)arr[i] = i + 1;
      do{
            if(a == -1 || b == -1){
                  for(int i = 0;i < n;i++){
                        if(arr[i] != arrp[i])break;
                        else if(i == n - 1)a = c;
                  }
                  for(int i = 0;i < n;i++){
                        if(arr[i] != arrq[i])break;
                        else if(i == n - 1)b = c;
                  }
            }
            else break;
            c++;
      }while(next_permutation(arr, arr + n));
      cout << abs(b - a);
}