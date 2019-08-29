#include<bits/stdc++.h>
using namespace std;

int main(){
      int a,b;
      cin >> a;
      int arra[a];
      for(int i = 0;i < a;i++)cin >> arra[i];
      cin >> b;
      int arrb[b];
      for(int i = 0;i < b;i++)cin >> arrb[i];
      sort(arra,arra+a);
      sort(arrb,arrb+b);
      cout << arra[a - 1] << " " << arrb[b - 1];

      return 0;
}