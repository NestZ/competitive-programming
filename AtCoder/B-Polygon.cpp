#include<bits/stdc++.h>
using namespace std;

int main(){
      int n;cin >> n;
      int sum = 0;
      int maxx = 0;
      for(int i = 0;i < n;i++){
            int l;cin >> l;
            if(l > maxx)maxx = l;
            sum += l;
      }
      if(maxx < sum - maxx)cout << "Yes";
      else cout << "No";
}