#include<bits/stdc++.h>

using namespace std;

int main(){
      int n;cin >> n;
      int c[5] = {0};
      for(int i = 0;i < n;i++){
            char temp;
            cin >> temp;
            if(temp == 'z')c[0]++;
            else if(temp == 'e')c[1]++;
            else if(temp == 'r')c[2]++;
            else if(temp == 'o')c[3]++;
            else c[4]++;
      }
      while(min(min(c[1],c[3]),c[4]) != 0){
            c[1]--;
            c[3]--;
            c[4]--;
            cout << 1 << " ";
      }
      while(min(min(min(c[0],c[1]),c[2]),c[3]) != 0){
            c[0]--;
            c[1]--;
            c[2]--;
            c[3]--;
            cout << 0 << " ";
      }
      return 0;
}