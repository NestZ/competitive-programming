#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	int n;cin >> n;
	int lst = 0;
	vector<int> ans;
	for(int i = 0;i < n;i++){
		int t;cin >> t;
		if(i == 0)lst = t;
		else{
			if(t == 1)ans.push_back(lst);
			lst = t;
		}
	}
	ans.push_back(lst);
	cout << ans.size() << endl;
	for(int i : ans)cout << i << ' ';
}
