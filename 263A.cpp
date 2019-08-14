#include<bits/stdc++.h>
using namespace std;

int main(){
      for(int i = 1;i <= 5;i++){
            for(int j = 1;j <= 5;j++){
                  int temp;
                  cin >> temp;
                  if(temp == 1)return cout << abs(j - 3) + abs(i - 3), 0;
            }
      }
      return 0;
}