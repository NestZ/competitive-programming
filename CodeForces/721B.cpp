#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, k;cin >> n >> k;
	vector<int> len(101, 0);
	for(int i = 0;i < n;i++){
		string s;cin >> s;
		len[s.length()]++;
	}
	string p;cin >> p;
	int l = p.length();
	int mn = 1;
	int mx = 0;
	for(int i = 0;i <= l;i++){
		if(i < l)mn += len[i];
		mx += len[i];
	}
	cout << mn + ((mn - 1) / k * 5) << ' ' << mx + ((mx - 1) / k * 5);
}
