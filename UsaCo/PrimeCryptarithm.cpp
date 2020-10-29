/*
ID: nestz
LANG: C++14
TASK: crypt1
*/
#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

set<int> num;

bool valid(int n){
	bool ans = true;
	while(n > 0){
		if(num.count(n % 10) == 0)return false;
		n /= 10;
	}
	return ans;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("crypt1.out", "w", stdout);
	freopen("crypt1.in", "r", stdin);
	
	int n;cin >> n;
	vector<int> pos3;
	vector<int> pos2;
	for(int i = 0;i < n;i++){
		int t;cin >> t;
		num.insert(t);
	}
	for(int i = 100;i <= 999;i++){
		if(valid(i))pos3.push_back(i);
	}
	for(int i = 10;i <= 99;i++){
		if(valid(i))pos2.push_back(i);
	}
	int ans = 0;
	for(int p3 : pos3){
		for(int p2 : pos2){
			int fst_par = p3 * (p2 % 10);
			int snd_par = p3 * (p2 / 10);
			if(to_string(fst_par).length() != 3 || to_string(snd_par).length() != 3)continue;
			int res = snd_par * 10 + fst_par;
			if(valid(fst_par) && valid(snd_par) && valid(res))ans++;
		}
	}
	cout << ans << endl;
}
