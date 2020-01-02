#include<bits/stdc++.h>
using namespace std;

int main(){
      int n;cin >> n;
      for(int i = n;i >= 0;i--){
            if(pow((int)sqrt(i), 2) == i)return cout << i, 0;
      }
}