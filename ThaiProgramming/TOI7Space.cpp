#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long int ll;

string to_bin(int n, int len){
	string res = "";
	while(n > 0){
		res += '0' + (n & 1);
		n >>= 1;
	}
	if(int(res.length()) < len)res += string(len - res.length(), '0');
	reverse(res.begin(), res.end());
	return res;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;cin >> n;
	set<pair<int, int>> ans;
	for(int i = 0;i < (1 << n);i++){
		for(int j = 0;j < n;j++){
			int fst = i;
			int snd = i ^ (1 << j);
			auto p = make_pair(min(fst, snd), max(fst, snd));
			if(!ans.count(p))ans.insert(p);
		}
	}
	for(auto p : ans){
		cout << to_bin(p.first, n) << ' ' << to_bin(p.second, n) << endl;
	}
}
