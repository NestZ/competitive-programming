#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	list<pair<int, int>> lp;
	map<int, int> m;
	vector<int> ans;
	int c, s;cin >> c >> s;
	for(int i = 0;i < s;i++){
		int tc, ts;cin >> tc >> ts;
		m[ts] = tc;
	}
	char op;cin >> op;
	while(op != 'X'){
		if(op == 'E'){
			int st;cin >> st;
			if(lp.size() == 0)lp.push_back({st, m[st]});
			else{
				list<pair<int, int>>::iterator tp = lp.end();
				for(list<pair<int, int>>::iterator p = lp.begin();p != lp.end();p++){
					if((*p).second == m[st])tp = p;
				}
				if(tp != lp.end())tp++;
				lp.insert(tp, make_pair(st, m[st]));
			}
		}
		else if(op == 'D'){
			ans.push_back(lp.front().first);
			lp.pop_front();
		}
		cin >> op;
	}
	for(int t : ans)cout << t << endl;
	cout << 0;
}
