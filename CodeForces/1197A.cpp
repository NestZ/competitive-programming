#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    for(int i = 0;i < n;i++){
        int num;
        cin >> num;
        int lenn = num + 10;
        int arr[lenn];
        for(int j = 0;j < num;j++)cin >> arr[j];
        sort(arr,arr + num);
        cout << min(num - 2,arr[num - 2] - 1) << '\n';
    }
    return 0;
}