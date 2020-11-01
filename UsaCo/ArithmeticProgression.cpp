/*
ID: nestz
LANG: C++14
TASK: ariprog
*/
#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

vector<bool> bis(126000, false);
int want_n;

bool check(int n, int m){
	for(int i = 0;i < want_n;i++){
		if(n + i * m > 62500 * 2)return false;
		if(bis[n + i * m] == false)return false;
	}
	return true;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("ariprog.out", "w", stdout);
	freopen("ariprog.in", "r", stdin);
	
	int m;cin >> want_n >> m;
	vector<pair<int, int>> ans;
	vector<int> all_bis;
	vector<int> diff;
	for(int p = 0;p <= m;p++){
		for(int q = p;q <= m;q++){
			bis[p * p + q * q] = true;
		}
	}
	for(int i = 0;i < 125001;i++){
		if(bis[i])all_bis.push_back(i);
	}
	int bis_cnt = all_bis.size();
	for(int i = 1;i < bis_cnt;i++){
		diff.push_back(all_bis[i] - all_bis[i - 1]);
	}
	for(int i = 0;i < bis_cnt;i++){
		int cur_dif = 0;
		for(int j = i + 1;j < bis_cnt;j++){
			cur_dif += diff[j - 1];
			if(check(all_bis[i], cur_dif)){
					ans.push_back(make_pair(cur_dif, all_bis[i]));
			}
		}
	}
	if(ans.size() == 0){
		cout << "NONE" << endl;
	}
	else{
		sort(ans.begin(), ans.end());
		for(pair<int, int> p : ans){
			cout << p.second << ' ' << p.first << endl;
		}
	}
}
