#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;cin >> n >> m;
	vector<tuple<int, int, int>> city;
	vector<string> ans(m);
	for(int i = 0;i < m;i++){
		int p, y;cin >> p >> y;
		city.emplace_back(p, y, i);
	}
	sort(city.begin(), city.end());
	int last = get<0>(city[0]);
	int cur_cnt = 1;
	for(int i = 0;i < m;i++){
		if(last != get<0>(city[i])){
			last = get<0>(city[i]);
			cur_cnt = 1;
		}
		string ind = to_string(cur_cnt);
		string pre = to_string(last);
		if(ind.length() < 6){
			string t = string(6 - ind.length(), '0');
			ind = t + ind;
		}
		if(pre.length() < 6){
			string t = string(6 - pre.length(), '0');
			pre = t + pre;
		}
		ans[get<2>(city[i])] = pre + ind;
		cur_cnt++;
	}
	for(string s : ans)cout << s << endl;
}
