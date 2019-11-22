#include<bits/stdc++.h>
using namespace std;

int main(){
      unsigned long long int sum = 0;
      cout << "{";
      for(int l = 1;l <= 300;l++){
            for(int i = 1;i <= l;i++){
                  for(int j = 1;j <= i + l;j++){
                        for(int k = 1;k <= l + i + j;k++){
                              sum += (i * j * k) % (i + j + k);
                        }
                  }
            }
            cout << sum << ", ";
            sum = 0;
      }
      cout << "}";
      return 0;
}