#include<bits/stdc++.h>
using namespace std;
//size_t f = string::npos
//make pair, tuple

int main(){
      int h,w;cin >> h >> w;
      char c[h + 5][w + 5];
      for(int i = 0;i < h;i++){
            for(int j = 0;j < w;j++){
                  cin >> c[i][j];
            }
            for(int j = 0;j < 2;j++){
                  for(int k = 0;k < w;k++){
                        cout << c[i][k];
                  }
                  cout << "\n";
            }
      }
}