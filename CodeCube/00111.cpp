#include<bits/stdc++.h>
using namespace std;

int main(){
      int a[5];
      int c[105];for(int &i : c)i = 0;
      int maxx = -1;
      int sum = 0;
      for(int i = 0;i < 3;i++){
            cin >> a[i];
            sum += a[i];
            c[a[i]]++;
            if(a[i] > maxx)maxx = a[i];
      }
      if(sum != 100)return cout << "BUG", 0;
      if(c[maxx] > 1)return cout << "I DON'T KNOW", 0;
      if(a[0] == maxx)cout << "PAPER";
      else if(a[1] == maxx)cout << "SCISSORS";
      else cout << "ROCK";
}