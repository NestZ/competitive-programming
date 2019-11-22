#include<bits/stdc++.h>
using namespace std;

int main(){
      int n;cin >> n;
      for(int i = 0;i < n;i++){
            int num;cin >> num;
            int sum = 0;
            for(int i = 0;i < num;i++){
                  int temp;cin >> temp;
                  sum += temp;
            }
            cout << (sum + (num - 1)) / num << "\n";
      }
      return 0;
}