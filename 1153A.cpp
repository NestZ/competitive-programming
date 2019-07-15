#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,t,ans;
    cin >> n >> t;
    int bus[n + 10][2];
    int min = 200000;
    for(int i = 0;i < n;i++)cin >> bus[i][0] >> bus[i][1];
    for(int i = 0;i < n;i++){
        while(bus[i][0] < t){
            bus[i][0] += bus[i][1];
        }
    }
    for(int i = 0;i < n;i++){
        if(bus[i][0] >= t && bus[i][0] - t < min){
            min = bus[i][0] - t;
            ans = i + 1;
        }
    }
    cout << ans;
    return 0;
}