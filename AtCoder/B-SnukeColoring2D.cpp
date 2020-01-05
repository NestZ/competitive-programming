#include<bits/stdc++.h>
using namespace std;
//size_t f = string::npos
//make pair, tuple

int main(){
      int w,h,n;cin >> w >> h >> n;
      int minX = 0;
      int minY = 0;
      int maxX = w;
      int maxY = h;
      for(int i = 0;i < n;i++){
            int x,y,a;cin >> x >> y >> a;
            if(a == 1)minX = max(minX, x);
            else if(a == 2)maxX = min(maxX, x);
            else if(a == 3)minY = max(minY,y);
            else maxY = min(maxY, y);
      }
      cout << (max(0, maxX - minX)) * max(0, (maxY - minY));
}