#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int lenn = n + 10;
    int arr[lenn] = {0};
    vector<int> ans;
    ans.push_back(1);
    for(int i = 0;i < n;i++)cin >> arr[i];
    int max = *max_element(arr,arr + n);
    int sum1 = arr[0];
    int sum2 = 0;
    int len = 1;
    for(int i = 1;i < n;i++){
        if(arr[0] / 2 >= arr[i]){
            sum1 += arr[i];
            ans.push_back(i+1);
            len++;
        }
        else sum2 += arr[i];
    }
    if(sum1 > sum2){
        cout << len << '\n';
        for(int i = 0;i < len;i++)cout << ans[i] << ' ';
        cout << '\n';
    }
    else cout << '0';
    return 0;
}