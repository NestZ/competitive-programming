#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;cin >> n;
	set<int> x;
	set<int> y;
	vector<int> ans;
	for(int i = 0;i < n * n;i++){
		int a, b;cin >> a >> b;
		if(x.count(a) == 0 && y.count(b) == 0){
			ans.push_back(i + 1);
			x.insert(a);
			y.insert(b);
		}
	}
	for(int i : ans)cout << i << ' ';
}
