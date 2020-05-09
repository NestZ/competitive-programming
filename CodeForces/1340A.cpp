#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;cin >> t;
	while(t--){
		int n;cin >> n;
		vector<int> p(n);
		for(int i = 0;i < n;i++)cin >> p[i];
		vector<int> pos(n);
		for(int i = 0;i < n;i++)pos[--p[i]] = i;
		vector<bool> was(n);
		bool flag = true;
		for(int i = 0;i < n;i++){
			if(was[i])continue;
			int me = pos[i];
			while(me < n){
				was[me] = true;
				if(me + 1 == n)break;
				if(was[me + 1])break;
				if(p[me + 1] == p[me] + 1){
					me++;
					continue;
				}
				flag = false;
				break;
			}
		}
		if(flag)cout << "Yes";
		else cout << "No";
		cout << endl;
	}
}
