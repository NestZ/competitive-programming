#include<bits/stdc++.h>
using namespace std;

int main(){
    int h,maxH,res;
    cin >> h >> maxH >> res;
    int ans[h + 10];
    int sum = 0;
    for(int i = 0;i < h;i++)ans[i] = maxH;
    for(int i = 0;i < res;i++){
        int l,r,H;
        cin >> l >> r >> H;
        for(int j = l - 1;j <= r - 1;j++){
            ans[j] = min(ans[j],H);
        }
    }
    for(int i = 0;i < h;i++){
        sum += pow(ans[i],2);
    }
    cout << sum;
    return 0;
}