#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	int n;cin >> n;
	vector<pair<int, int>> arr(n);
	for(int i = 0;i < n;i++){
		cin >> arr[i].first >> arr[i].second;
	}
	int ans = 0;
	for(int i = 0;i < n;i++){
		for(int j = 0;j < n;j++){
			if(i == j)continue;
			if(arr[i].first == arr[j].second)ans++;
		}
	}
	cout << ans;
}
