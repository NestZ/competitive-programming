#include<bits/stdc++.h>
using namespace std;

int main(){
      int x1,y1,x2,y2;cin >> x1 >> y1 >> x2 >> y2;
      int x = x2 - x1;
      int y = y2 - y1;
      cout << x2 - y << " " << y2 + x << " " << x1 - y << " " << y1 + x;
}