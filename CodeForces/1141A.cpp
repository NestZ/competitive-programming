#include<bits/stdc++.h>
using namespace std;

int main(){
      int a,b;
      cin >> a >> b;
      if(a == b)return cout << 0, 0;
      else if(a > b/2 || b % a != 0)return cout << "-1" , 0;
      else if(b % a == 0){
            int n = 0;
            while(a != b){
                  if(b % (a * 2) == 0)a *= 2;
                  else if(b % (a * 3) == 0)a *= 3;
                  else return cout << "-1" , 0;
                  n++;
            }
            cout << n;
      }
      return 0;
}