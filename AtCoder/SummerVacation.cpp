#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;cin >> n >> m;
	int ans = 0;
	int ptr = 0;
	vector<pair<int, int>> arr;
	priority_queue<int> q;
	for(int i = 0;i < n;i++){
		int a, b;cin >> a >> b;
		arr.emplace_back(a, b);
	}
	sort(arr.begin(), arr.end());
	for(int i = 1;i <= m;i++){
		while(ptr < n && arr[ptr].first <= i){
			q.push(arr[ptr].second);
			ptr++;
		}
		if(q.empty())continue;
		ans += q.top();
		q.pop();
	}
	cout << ans << endl;
}
