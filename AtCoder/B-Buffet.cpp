#include<bits/stdc++.h>
using namespace std;

int main(){
      int n;cin >> n;
      int sum = 0;
      int arra[n + 10];for(int i = 0;i < n;i++)cin >> arra[i];
      int arrb[n + 10];
      for(int i = 0;i < n;i++)cin >> arrb[i];
      int arrc[n + 10];
      for(int i = 0;i < n - 1;i++)cin >> arrc[i];
      for(int i = 0;i < n;i++){
            sum += arrb[arra[i] - 1];
            if(i > 0 && arra[i] == arra[i - 1] + 1)sum += arrc[arra[i - 1] - 1];
      }
      cout << sum;
}