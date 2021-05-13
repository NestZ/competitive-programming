/*
ID: nestz
LANG: C++14
TASK: shell
*/
#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("shell.out", "w", stdout);
	freopen("shell.in", "r", stdin);

	int n;cin >> n;
	vector<pair<pair<int, int>, int>> arr;
	for(int i = 0;i < n;i++){
		int a, b, g;cin >> a >> b >> g;
		arr.push_back({{a, b}, g});
	}
	int ans = 0;
	for(int i = 1;i <= n;i++){
		vector<int> state(n + 1, 0);
		state[i] = 1;
		int cnt = 0;
		for(int j = 0;j < n;j++){
			int fst = arr[j].first.first;
			int snd = arr[j].first.second;
			int g = arr[j].second;
			swap(state[fst], state[snd]);
			cnt += state[g];
		}
		ans = max(ans, cnt);
	}
	cout << ans << endl;
}
