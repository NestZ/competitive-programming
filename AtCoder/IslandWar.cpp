#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;cin >> n >> m;
	vector<pair<int, int>> arr;
	for(int i = 0;i < m;i++){
		int a, b;cin >> a >> b;
		arr.emplace_back(b, a);
	}
	sort(arr.begin(), arr.end());
	int lst = arr[0].first;
	int ans = 1;
	for(int i = 1;i < m;i++){
		if(arr[i].second < lst)continue;
		lst = arr[i].first;
		ans++;
	}
	cout << ans << endl;
}
