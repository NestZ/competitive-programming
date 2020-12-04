#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;cin >> t;
	while(t--){
		int a, b;cin >> a >> b;
		set<int> s;
		int ans = 0;
		for(int i = 0;i < a;i++){
			int num;cin >> num;
			s.insert(num);
		}
		for(int i = 0;i < b;i++){
			int num;cin >> num;
			if(s.count(num))ans++;
		}
		cout << ans << endl;
	}
}
