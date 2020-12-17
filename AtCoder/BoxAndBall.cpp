#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;cin >> n >> m;
	vector<pair<bool, int>> arr(n + 1, make_pair(false, 1));
	arr[1].first = true;
	for(int i = 0;i < m;i++){
		int a, b;cin >> a >> b;
		if(arr[a].first){
			if(arr[a].second == 1)arr[a].first = false;
			arr[b].first = true;
		}
		arr[a].second--;
		arr[b].second++;
	}
	int ans = 0;
	for(auto p : arr)if(p.first)ans++;
	cout << ans << endl;
}
