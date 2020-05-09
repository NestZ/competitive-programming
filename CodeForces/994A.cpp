#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;cin >> n >> m;
	vector<int> arr(n);
	for(int i = 0;i < n;i++)cin >> arr[i];
	set<int> s;
	for(int i = 0;i < m;i++){
		int t;cin >> t;
		s.insert(t);
	}
	for(int i : arr)if(s.count(i) > 0)cout << i << ' ';
}
