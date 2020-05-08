#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, k;cin >> n >> k;
	queue<int> q;
	set<int> s;
	vector<int> ans;
	for(int i = 0;i < n;i++){
		int t;cin >> t;
		if(s.count(t) == 0){
			if(q.size() < k)q.push(t);
			else{
				int temp = q.front();
				q.pop();
				s.erase(temp);
				q.push(t);
			}
		}
		s.insert(t);
	}
	while(!q.empty()){
		ans.push_back(q.front());
		q.pop();
	}
	reverse(ans.begin(), ans.end());
	cout << ans.size() << endl;
	for(int i : ans)cout << i << ' ';
}
