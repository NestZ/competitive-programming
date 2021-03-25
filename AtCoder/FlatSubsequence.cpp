#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long int ll;
int m = 600010;
int n, k;
vector<int> st(2000000, 0);

int mx(int a, int b){
	a += m; b += m;
	int res = 0;
	while(a <= b){
		if(a % 2 == 1)res = max(res, st[a++]);
		if(b % 2 == 0)res = max(res, st[b--]);
		a /= 2; b /= 2;
	}
	return res;
}

void update(int pos, int d){
	pos += m;
	st[pos] = max(st[pos], d);
	for(pos /= 2;pos >= 1;pos /= 2){
		st[pos] = max(st[2 * pos], st[2 * pos + 1]);
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> k;
	int ans = 0;
	vector<int> mxl(n);
	for(int i = 0;i < n;i++){
		int num;cin >> num;
		mxl[i] = 1 + mx(max(0, num - k), num + k);
		ans = max(ans, mxl[i]);
		update(num, mxl[i]);
	}
	cout << ans << endl;
}
