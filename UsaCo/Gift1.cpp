/*
ID: nestz
LANG: C++14
TASK: gift1
*/
#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("gift1.out", "w", stdout);
	freopen("gift1.in", "r", stdin);

	int n;cin >> n;
	int money[20] = {0};
	vector<string> name;
	map<string, int> ind;
	for(int i = 0;i < n;i++){
		string s;cin >> s;
		name.push_back(s);
		ind[s] = i;
	}
	for(int i = 0;i < n;i++){
		string cur;cin >> cur;
		int give, num;cin >> give >> num;
		if(num == 0)continue;
		int giveEach = give / num;
		int remain = give - (giveEach * num);
		money[ind[cur]] -= give;
		money[ind[cur]] += remain;	
		for(int j = 0;j < num;j++){
			string given;cin >> given;
			money[ind[given]] += giveEach;
		}
	}
	for(string s : name){
		cout << s << ' ' << money[ind[s]] << endl;
	}
}
