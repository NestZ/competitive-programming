#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;cin >> n;
	deque<int> q;
	for(int i = 0;i < n;i++){
		int num;cin >> num;
		if(i & 1)q.push_front(num);
		else q.push_back(num);
	}
	vector<int> ans;
	while(!q.empty()){
		ans.push_back(q.front());
		q.pop_front();
	}
	if(n & 1)reverse(ans.begin(), ans.end());
	for(int i : ans)cout << i << ' ';
	cout << endl;
}
