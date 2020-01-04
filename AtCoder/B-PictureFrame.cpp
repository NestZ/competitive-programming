#include<bits/stdc++.h>
using namespace std;
//size_t f = string::npos
//make pair, tuple

int main(){
      int n,m;cin >> n >> m;
      char arr[n + 5][m + 5];
      for(int i = 0;i < m + 2;i++)cout << '#';
      cout << "\n";
      for(int i = 0;i < n;i++){
            cout << '#';
            for(int i = 0;i < m;i++){
                  char t;cin >> t;
                  cout << t;
            }
            cout << "#\n";
      }
      for(int i = 0;i < m + 2;i++)cout << '#';
}