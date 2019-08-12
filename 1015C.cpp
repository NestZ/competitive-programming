#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,max;
    long long int sum = 0;
    long long int sumCheck = 0;
    cin >> n >> max;
    int arr[n];
    int ans = 0;
    for(int i = 0;i < n;i++){
        int t1,t2;
        cin >> t1 >> t2;
        sum += t1;
        sumCheck += t2;
        arr[i] = t1 - t2;
        if(sumCheck > max)return cout << "-1", 0;
    }
    sort(arr,arr+n);
    for(int i = n - 1;i >= 0;i--){
        if(sum > max){
            sum -= arr[i];
            ans++;
        }
        else break;
    }
    if(sum > max)cout << "-1";
    else cout << ans;
    return 0;
}