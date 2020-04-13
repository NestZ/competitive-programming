#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	int t;cin >> t;
	while(t--){
		int n;cin >> n;
		vector<int> arr(n);
		set<int> s;
		int mx = 0;
		map<int ,int> m;
		for(int i = 0;i < n;i++){
			cin >> arr[i];
			m[arr[i]]++;
			mx = max(mx, m[arr[i]]);
			s.insert(arr[i]);
		}
		int si = s.size();
		if(mx < si)cout << mx;
		else cout << min(mx - 1, si);
		cout << endl;
	}
}
