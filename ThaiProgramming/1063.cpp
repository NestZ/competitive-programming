#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

map<pair<char, char>, vector<int>> g;
map<char, bool> vis;
vector<pair<char, char>> path;

double med(vector<int> arr){
	int n = arr.size();
	sort(arr.begin(), arr.end());
	if(n % 2 == 0){
		return (arr[n / 2] + arr[n / 2 - 1]) / 2.0;
	}
	return arr[n / 2];
}

bool dfs(char cur){
	vis[cur] = true;
	if(cur == 'Y')return true;
	for(auto p : g){
		if(p.first.first != cur)continue;
		if(vis[p.first.second])continue;
		path.push_back(make_pair(cur, p.first.second));
		bool b = dfs(p.first.second);
		if(!b)path.pop_back();
		else return true;
	}
	return false;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;cin >> n;
	for(int i = 0;i < n;i++){
		char a, b;cin >> a >> b;
		int d;cin >> d;
		pair<char, char> p1 = make_pair(a, b);
		pair<char, char> p2 = make_pair(b, a);
		g[p1].push_back(d);
		g[p2].push_back(d);
	}
	dfs('X');
	double all_cost = 0;
	if(path.size() == 0)return cout << "broken\n", 0;
	for(auto ans : path){
		pair<char, char> p = make_pair(ans.first, ans.second);
		vector<int> this_cost = g[p];
		double cost = med(this_cost);
		printf("%c %c %.1f\n", ans.first, ans.second, cost);
		all_cost += cost;
	}
	printf("%.1f\n", all_cost);
}
