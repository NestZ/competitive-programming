#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;cin >> n;
    vector<pair<int, int>> vp;
    for(int i = 0;i < n;i++){
        int a, b;cin >> a >> b;
        vp.push_back(make_pair(a, b));
    }
    double ans = 0;
    for(int i = 0;i < n;i++){
        for(int j = i + 1;j < n;j++){
            for(int k = j + 1;k < n;k++){
                ans = max(ans, abs((vp[i].first * vp[j].second) + (vp[j].first * vp[k].second) + (vp[k].first * vp[i].second) - (vp[i].second * vp[j].first) - (vp[j].second * vp[k].first) - (vp[k].second * vp[i].first)) / 2.0);
            }
        }
    }
    printf("%.3f", ans);
}