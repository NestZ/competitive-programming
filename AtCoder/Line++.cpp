#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
int num, x, y;
vector<int> cnt(2001, 0);
vector<bool> vis(2001, false);

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> num >> x >> y;
	queue<pair<int, int>> q;
	for(int i = 1;i <= num;i++){
		q.emplace(i, 0);
		vis[i] = true;
		while(!q.empty()){
			auto p = q.front();q.pop();
			int n = p.first;
			int d = p.second;
			cnt[d]++;
			if(n == x && !vis[y]){
				vis[y] = true;
				q.emplace(y, d + 1);
			}
			if(n == y && !vis[x]){
				vis[x] = true;
				q.emplace(x, d + 1);
			}
			if(n - 1 > 0 && !vis[n - 1]){
				vis[n - 1] = true;
				q.emplace(n - 1, d + 1);
			}
			if(n + 1 <= num && !vis[n + 1]){
				vis[n + 1] = true;
				q.emplace(n + 1, d + 1);
			}
		}
		vis = vector<bool>(2001, false);
	}
	for(int i = 1;i < num;i++)
		cout << cnt[i] / 2 << endl;
}
