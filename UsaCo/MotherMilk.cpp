/*
ID: nestz
LANG: C++14
TASK: milk3
*/
#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("milk3.out", "w", stdout);
	freopen("milk3.in", "r", stdin);
	
	int ma, mb, mc;cin >> ma >> mb >> mc;
	set<tuple<int, int, int>> vis;
	set<int> ans;
	vector<int> real_ans;
	queue<tuple<int, int, int>> q;
	q.push(make_tuple(0, 0, mc));
	while(!q.empty()){
		tuple<int, int, int> cur = q.front();
		q.pop();
		if(get<0>(cur) == 0)ans.insert(get<2>(cur));
		if(vis.count(cur) > 0)continue;
		vis.insert(cur);
		//iterate through possible states
		//a have milk
		if(get<0>(cur) > 0){
			int cur_a = get<0>(cur);
			int cur_b = get<1>(cur);
			int cur_c = get<2>(cur);
			int new_a = cur_a;
			int new_b = cur_b;
			int new_c = cur_c;
			int can_pour = 0;
			//b not max
			if(cur_b < mb){
				can_pour = min(cur_a, mb - cur_b);
				new_a = cur_a - can_pour;
				new_b = cur_b + can_pour;
				if(vis.count(make_tuple(new_a, new_b, cur_c)) == 0)
					q.push(make_tuple(new_a, new_b, cur_c));
			}
			//c not max
			if(cur_c < mc){
				can_pour = min(cur_a, mc - cur_c);
				new_a = cur_a - can_pour;
				new_c = cur_c + can_pour;
				if(vis.count(make_tuple(new_a, cur_b, new_c)) == 0)
					q.push(make_tuple(new_a, cur_b, new_c));
			}
		}
		//b have milk
		if(get<1>(cur) > 0){
			int cur_a = get<0>(cur);
			int cur_b = get<1>(cur);
			int cur_c = get<2>(cur);
			int new_a = cur_a;
			int new_b = cur_b;
			int new_c = cur_c;
			int can_pour = 0;
			//a not max
			if(cur_a < ma){
				can_pour = min(cur_b, ma - cur_a);
				new_b = cur_b - can_pour;
				new_a = cur_a + can_pour;
				if(vis.count(make_tuple(new_a, new_b, cur_c)) == 0)
					q.push(make_tuple(new_a, new_b, cur_c));
			}
			//c not max
			if(cur_c < mc){
				can_pour = min(cur_b, mc - cur_c);
				new_b = cur_b - can_pour;
				new_c = cur_c + can_pour;
				if(vis.count(make_tuple(cur_a, new_b, new_c)) == 0)
					q.push(make_tuple(cur_a, new_b, new_c));
			}
		}
		//c have milk
		if(get<2>(cur) > 0){
			int cur_a = get<0>(cur);
			int cur_b = get<1>(cur);
			int cur_c = get<2>(cur);
			int new_a = cur_a;
			int new_b = cur_b;
			int new_c = cur_c;
			int can_pour = 0;
			//a not max
			if(cur_a < ma){
				can_pour = min(cur_c, ma - cur_a);
				new_c = cur_c - can_pour;
				new_a = cur_a + can_pour;
				if(vis.count(make_tuple(new_a, cur_b, new_c)) == 0)
					q.push(make_tuple(new_a, cur_b, new_c));
			}
			//b not max
			if(cur_b < mb){
				can_pour = min(cur_c, mb - cur_b);
				new_c = cur_c - can_pour;
				new_b = cur_b + can_pour;
				if(vis.count(make_tuple(cur_a, new_b, new_c)) == 0)
					q.push(make_tuple(cur_a, new_b, new_c));
			}
		}
	}
	for(int i : ans)real_ans.push_back(i);
	int len = real_ans.size();
	for(int i = 0;i < len;i++){
		cout << real_ans[i];
		if(i != len - 1)cout << ' ';
	}
	cout << endl;
}
