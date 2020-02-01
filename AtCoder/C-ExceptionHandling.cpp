#include<bits/stdc++.h>
using namespace std;
// make pair, tuple
// __gcd(int, int)
// bool isPrime(int n){
//       if(n <= 1)return false;
//       if(n <= 3)return true;
//       if(n % 2 == 0 || n % 3 == 0)return false;
//       for(int i = 5;i * i <= n;i += 6){
//             if(n % i == 0 || n % (i + 2) == 0)return false;
//       }
//       return true;
// }
// int countSubString(string s, string temp){
//       int ans = 0;
//       size_t f = s.find(temp);
//       while(f != string::npos){
//             ans++;
//             f = s.find(temp, f + 1);
//       }
//       return ans;
// }

int main(){
    int n;cin >> n;
    int arr[n + 5];
    int maxx = 0;
    int maxx2 = 0;
    for(int i = 0;i < n;i++){
        cin >> arr[i];
        if(arr[i] > maxx){
            maxx2 = maxx;
            maxx = arr[i];
        }
        else if(arr[i] > maxx2)maxx2 = arr[i];
    }
    for(int i = 0;i < n;i++){
        if(arr[i] == maxx)cout << maxx2<< "\n";
        else cout << maxx << "\n";
    }
}