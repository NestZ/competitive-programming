#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,x,y;
    cin >> n >> x >> y;
    int lenn = n + 10;
    int arr[lenn] = {0};
    int ans = n;
    for(int i = 0;i < n;i++)cin >> arr[i];
    for(int i = 0;i < n;i++){
        int el = min(n - 1,i + y);
        int sl = max(0,i - x);
        for(int j = sl;j <= el;j++){
            if(arr[i] > arr[j])break;
            else if(j == el && arr[i] < arr[j] || el == sl)ans = min(i + 1,ans);
        }
    }
    cout << ans;
    return 0;
}