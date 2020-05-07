#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;cin >> n;
	vector<int> e;
	vector<int> o;
	for(int i = 0;i < n;i++){
		int t;cin >> t;
		if(t & 1)o.push_back(t);
		else e.push_back(t);
	}
	if(abs((int)e.size() - (int)o.size()) <= 1)cout << 0;
	else{
		int ans = 0;
		sort(e.rbegin(), e.rend());
		sort(o.rbegin(), o.rend());
		if(e.size() > o.size())for(int i = o.size() + 1;i < e.size();i++)ans += e[i];
		else for(int i = e.size() + 1;i < o.size();i++)ans += o[i];
		cout << ans;
	}
}
