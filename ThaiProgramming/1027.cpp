#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	string s;cin >> s;
	map<char, int> m;
	char carr[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};
	int failed = 0;
	for(char c : carr)m[c] = 0;
	while(s != "!"){
		int n = s.length();
		int minn = INT_MAX;
		vector<char> fail;
		for(int i = 0;i < n;i++)if(m[s[i]] != -1)m[s[i]]++;
		for(pair<char, int> p : m){
			if(p.second != -1){
				if(p.second < minn){
					minn = p.second;
					fail.clear();
					fail.push_back(p.first);
				}
				else if(p.second == minn)fail.push_back(p.first);
			}
		}
		if(fail.size() == 1 && failed < 6){
			m[fail.front()] = -1;
			failed++;
		}
		cin >> s;
	}
	vector<pair<int, char>> ans;
	for(pair<char, int> p : m){
		if(p.second != -1)ans.push_back({-p.second, p.first});
	}
	sort(ans.begin(), ans.end());
	cout << ans.size() << endl;
	for(pair<int, char> p : ans)cout << p.second << ' ' << p.first * -1 << endl;
}
