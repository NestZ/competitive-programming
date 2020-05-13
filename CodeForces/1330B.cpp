#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

const int N = 200005;

bool ch(vector<int> &arr, int s, int e){
	vector<bool> u(N, false);
	int mx = 0;
	for(int i = s;i <= e;i++){
		if(u[arr[i]])return false;
		u[arr[i]] = true;
		mx = max(mx, arr[i]);
	}
	if(mx != e - s + 1)return false;
	return true;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;cin >> t;
	while(t--){
		int n;cin >> n;
		vector<int> arr(n);
		set<pair<int, int>> ans;
		vector<bool> u(N, false);
		int ma = 0;
		for(int i = 0;i < n;i++){
			cin >> arr[i];
			ma = max(ma, arr[i]);
		}
		if(ch(arr, 0, ma - 1) && ch(arr, ma, n - 1)){
			ans.insert({ma, n - ma});
		}
		if(ch(arr, 0, n - ma - 1) && ch(arr, n - ma, n - 1)){
			ans.insert({n - ma, ma});
		}
		if(ans.size() > 0){
			cout << ans.size() << endl;
			for(pair<int, int> p : ans)cout << p.first << ' ' << p.second << endl;
		}
		else cout << 0 << endl;
	}	
}
