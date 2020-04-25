#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, k;cin >> n >> k;
	vector<int> arr(n);
	set<int> s;
	for(int i = 0;i < n;i++){
		cin >> arr[i];
		s.insert(arr[i]);
	}
	if(s.size() < k)return cout << "NO", 0;
	cout << "YES" << endl;
	map<int, int> m;
	for(int i = 0;i < n && k > 0;i++){
		if(m[arr[i]] == 0){
			cout << i + 1 << ' ';
			m[arr[i]]++;
			k--;
		}
	}
}
