/*
ID: nestz
LANG: C++14
TASK: beads
*/
#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("beads.out", "w", stdout);
	freopen("beads.in", "r", stdin);
	
	int n;cin >> n;
	string b;cin >> b;
	b += b;
	vector<int> mxf(n, 0);
	vector<int> mxb(n, 0);
	for(int i = 0;i < n;i++){
		int curf = 0;
		char cur_ch = b[i];
		for(int j = i;j < i + n;j++){
			if(cur_ch == 'w' && b[j] != 'w')cur_ch = b[j];
			if(b[j] == cur_ch || b[j] == 'w')curf++;
			else break;
		}
		mxf[i] = curf;
	}
	for(int i = n;i < 2 * n;i++){
		int curb = 0;
		char cur_ch = b[i % n];
		for(int j = i;j > i - n;j--){
			if(cur_ch == 'w' && b[j] != 'w')cur_ch = b[j];
			if(b[j] == cur_ch || b[j] == 'w')curb++;
			else break;
		}
		mxb[i % n] = curb;
	}
	int ans = mxf[0] + mxb[n - 1];
	for(int i = 1;i < n;i++){
		ans = max(ans, mxf[i] + mxb[i - 1]);
	}
	cout << min(ans, n) << endl;
}
