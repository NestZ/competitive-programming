/*
ID: nestz
LANG: C++14
TASK: hamming
*/
#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int dis(int a, int b){
	int n = a ^ b;
	return __builtin_popcount(n);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("hamming.out", "w", stdout);
	freopen("hamming.in", "r", stdin);
	
	int n, b, d;cin >> n >> b >> d;
	vector<int> ans;
	ans.push_back(0);
	for(int i = 0;i < (1 << b);i++){
		bool flag = true;
		for(int num : ans){
			if(dis(i, num) < d)flag = false;
		}
		if(flag)ans.push_back(i);
	}
	for(int i = 1;i <= n;i++){
		cout << ans[i - 1];
		if(i % 10 == 0)cout << endl;
		else if(i != n)cout << ' ';
	}
	if(n % 10 != 0)cout << endl;
}
