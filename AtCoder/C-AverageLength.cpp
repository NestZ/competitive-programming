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

double dist(pair<int, int> p1, pair<int, int> p2){
    return sqrt(pow(p1.first - p2.first, 2) + pow(p1.second - p2.second, 2));
}

int main(){
    int n;cin >> n;
    double ans = 0;
    int arr[n + 5];
    int fac = 0;
    vector<pair<int, int>> vp;
    for(int i = 1;i <= n;i++)arr[i - 1] = i;
    for(int i = 0;i < n;i++){
        int a,b;cin >> a >> b;
        vp.push_back({a, b});
    }
    do{
        fac++;
        pair<int, int> curr = vp[arr[0] - 1];
        for(int i = 1;i < n;i++){
            ans += dist(vp[arr[i] - 1], curr);
            curr = vp[arr[i] - 1];
        }
    }while(next_permutation(arr, arr + n));
    printf("%.10f", ans / fac);
}