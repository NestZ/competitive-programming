#include<bits/stdc++.h>
using namespace std;

int main(){
      int a = 1;
      int b = 2;
      int x,y;cin >> x >> y;
      int aa = 0;
      int bb = 0;
      while(aa - x != bb - y){
            aa = (a*(a - 1)) / 2;
            bb = (b*(b - 1)) / 2;
            a++;b++;
      }
      cout << aa - x;
}