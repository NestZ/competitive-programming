#include<bits/stdc++.h>
using namespace std;

int main(){
    deque<int> d;
    int e;
    int n;
    cin >> e >> n;
    int lenn = n + 10;
    int lene = e + 10;
    long long int arr[lenn];
    long long int count = 0;
    int que[lene];
    int maxE = 0;
    for(int i = 0;i < e;i++){
        cin >> que[i];
        if(que[i] > maxE)maxE = que[i];
    }
    for(int i = 0;i < n;i++)cin >> arr[i];
    for(int i = 0;i < e;i++)d.push_back(que[i]);
    for(int i = 0;i < n;i++){
        if(arr[i] >= e){
            if(count == 0){
                while(maxE != d.front()){
                    if(d.at(0) > d.at(1)){
                        int temp = d.at(0);
                        d.at(0) = d.at(1);
                        d.at(1) = temp;
                        d.push_back(d.at(0));
                        d.pop_front();
                    }
                    else{
                        d.push_back(d.at(0));
                        d.pop_front();
                    }
                    count++;
                }
            }
            int index = (arr[i] - count - 1) % (e - 1);
            cout << maxE << ' ' << d[index + 1] << '\n';
        }
        else{
            int maxNum = 0;
            for(int j = 0;j < arr[i];j++)if(que[j] > maxNum)maxNum = que[j];
            cout << maxNum << ' ' << que[arr[i]] << '\n';
        }
    }

    return 0;
}