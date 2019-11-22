#include<bits/stdc++.h>
using namespace std;

int main(){
      int w1,h1,w2,h2;cin >> w1 >> h1 >> w2 >> h2;
      cout << w1*2 + h1*2 + 4 + w2*2 + h2*2 + 4 - min(w1*2 + 4,w2*2 + 4);
      return 0;
}