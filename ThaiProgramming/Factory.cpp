#include<bits/stdc++.h>
using namespace std;
 
int main(){
    int sum = 0;
    int n;cin >> n;
    vector<int> arr(n);
    int ans = INT_MAX;
    int fst, snd;
    if(n == 1){
        int t;cin >> t;
        return cout << t, 0;
    }
    else if(n == 2){
        int a, b;cin >> a >> b;
        return cout << max(a, b), 0;
    }
    for(int i = 0;i < n;i++){
        cin >> arr[i];
        sum += arr[i];
    }
    int a = 0, b = 0, c = 0;
    for(int i = 0;i < n - 2;i++){
        a += arr[i];
        b = 0;
        for(int j = i + 1;j < n - 1;j++){
            b += arr[j];
            c = sum - (a + b);
            int curr = max({a, b, c}) - min({a, b, c});
            if(curr < ans){
                fst = i + 1;
                snd = j + 1;
                ans = curr;
            }
        }
    }
    cout << fst + 1 << ' ' << snd + 1;
}
