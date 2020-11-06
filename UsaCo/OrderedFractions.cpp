/*
ID: nestz
LANG: C++14
TASK: frac1
*/
#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

bool comp(pair<int, int> fst, pair<int, int> snd){
	int fst_val = fst.first * snd.second;
	int snd_val = fst.second * snd.first;
	return fst_val < snd_val;
}

pair<int, int> mn_frac(pair<int, int> p){
	for(int i = 2;i <= p.second;i++){
		while(p.first % i == 0 && p.second % i == 0){
			p.first /= i;
			p.second /= i;
		}
	}
	return p;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("frac1.out", "w", stdout);
	freopen("frac1.in", "r", stdin);
	
	int n;cin >> n;
	set<pair<int, int>> s;
	vector<pair<int, int>> arr;
	for(int i = 1;i <= n;i++){
		for(int j = 0;j <= i;j++){
			pair<int, int> p = make_pair(j, i);
			s.insert(mn_frac(p));
		}
	}
	for(pair<int, int> p : s)arr.push_back(p);
	sort(arr.begin(), arr.end(), comp);
	for(pair<int, int> p : arr){
		cout << p.first << '/' << p.second << endl;
	}
}
