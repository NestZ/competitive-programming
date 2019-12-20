#include<bits/stdc++.h>
using namespace std;

int main(){
      int curr;cin >> curr;
      map<int, int> m;
      m[curr] = 1;
      int i = 1;
      while(true){
            i++;
            if(curr & 1)curr = (3 * curr) + 1;
            else curr /= 2;
            m[curr]++;
            if(m[curr] == 2)return cout << i, 0;
      }
}