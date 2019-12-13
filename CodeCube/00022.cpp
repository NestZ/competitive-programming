#include<bits/stdc++.h>
using namespace std;

int main(){
      int num;scanf("%d", &num);
      bool n[1010][1010];
      int ans = 0;
      for(int i = 0;i < 1000;i++){
            for(int j = 0;j < 1000;j++){
                  n[i][j] = false;
            }
      }
      for(int i = 0;i < num;i++){
            int a,b;scanf("%d %d", &a, &b);
            if(n[a][b] == false){
                  n[a][b] = true;
                  ans++;
            }
      }
      printf("%d", ans);
}