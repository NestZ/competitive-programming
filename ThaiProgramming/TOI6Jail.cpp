#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;cin >> n >> m;
	int killed = 0;
	int cur = 0;
	vector<bool> die(n + 1, false);
	while(killed < n){
		for(int i = 1;i <= n;i++){
			if(die[i])continue;
			cur++;
			if(cur == m){
				cur = 0;
				die[i] = true;
				killed++;
				cout << i << ' ';
			}
		}
	}
	cout << endl;
}
