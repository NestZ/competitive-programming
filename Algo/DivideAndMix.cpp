#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
set<ll> ans;

void divide(vector<int> &arr){
	int mx = INT_MIN;
	int mn = INT_MAX;
	ll sum = 0;
	for(int i : arr){
		mx = max(mx, i);
		mn = min(mn, i);
		sum += i;
	}
	int mid = (mx + mn) / 2;
	ans.insert(sum);
	vector<int> a1;
	vector<int> a2;
	for(int i : arr){
		if(i <= mid)a1.emplace_back(i);
		else a2.emplace_back(i);
	}
	if(a1.size() == 0 || a2.size() == 0)return;
	divide(a1);
	divide(a2);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;cin >> t;
	while(t--){
		int n, q;cin >> n >> q;
		vector<int> arr(n);
		for(int i = 0;i < n;i++)cin >> arr[i];
		divide(arr);
		for(int i = 0;i < q;i++){
			int sum;cin >> sum;
			if(ans.count(sum))cout << "Yes";
			else cout << "No";
			cout << endl;
		}
		ans = set<ll>();
	}
}
