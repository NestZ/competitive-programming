/*
ID: nestz
LANG: C++14
TASK: skidesign
*/
#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("skidesign.out", "w", stdout);
	freopen("skidesign.in", "r", stdin);
	
	int n;cin >> n;
	vector<int> arr(n);
	for(int i = 0;i < n;i++)cin >> arr[i];
	int ans = INT_MAX;
	for(int s = 0;s <= 83;s++){
		int cost = 0;
		for(int i = 0;i < n;i++){
			if(arr[i] < s){
				cost += (s - arr[i]) * (s - arr[i]);
			}
			else if(arr[i] > s + 17){
				cost += (arr[i] - s - 17) * (arr[i] - s - 17);
			}
		}
		ans = min(ans, cost);
	}
	cout << ans << endl;
}
