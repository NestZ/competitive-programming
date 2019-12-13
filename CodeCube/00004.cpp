#include<bits/stdc++.h>
using namespace std;

long long int gcd(long long int a, long long int b){
      if(a == 0)return b;
      return gcd(b % a, a);
}

long long int gcd2(long long int arr[], int n){
      int res = arr[0];
      for(int i = 0;i < n;i++){
            res = gcd(arr[i], res);
            if(res == 1)return 1;
      }
      return res;
}

int main(){
      int n;cin >> n;
      long long int *arr = new long long int[n + 10];
      for(int i = 0;i < n;i++){
            cin >> arr[i];
      }
      bool flag = false;
      long long int gcd = gcd2(arr, n);
      long long int ans = 0;
      for(int i = 0;i < n;i++){
            ans += arr[i] / gcd;
      }
      cout << ans;
}