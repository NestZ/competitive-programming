#include<bits/stdc++.h>
using namespace std;

int main(){
    long long int n;
    int m;
    long long int k;
    long long int ans = 0;
    cin >> n >> m >> k;
    int len = m + 10;
    long long int dis[len] = {0};
    int indexCount = 0;
    long long int start = 0;
    int count = 0;
    for(int i = 0;i < m;i++){
        cin >> dis[i];
    }
    while(1){
        if(start > n || indexCount > m - 1){
            break;
        }
        for(int i = indexCount;i < m;i++){
            if(dis[i] <= start + k){
                count++;
                indexCount++;
            }
            else break;
        }
        if(count != 0){
            start += count;
            count = 0;
            ans++;
        }
        else{
            long long int skip = (dis[indexCount] - start) % k;
            if(skip == 0)skip += k;
            start = dis[indexCount] - skip;
        }
    }
    cout << ans;
    return 0;
}