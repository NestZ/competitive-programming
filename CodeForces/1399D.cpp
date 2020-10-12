#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;cin >> t;
	while(t--){
		int n;cin >> n;
		string s;cin >> s;
		set<int> foro;
		set<int> forz;
		int curcnt = 0;
		vector<int> ans(n);
		for(int i = 0;i < n;i++){
			if(s[i] == '0'){
				if(forz.size() == 0){
					curcnt++;
					foro.insert(curcnt);
					ans[i] = curcnt;
				}
				else{
					ans[i] = *forz.begin();
					foro.insert(ans[i]);
					forz.erase(forz.begin());
				}
			}
			else{
				if(foro.size() == 0){
					curcnt++;
					forz.insert(curcnt);
					ans[i] = curcnt;
				}
				else{
					ans[i] = *foro.begin();
					forz.insert(ans[i]);
					foro.erase(foro.begin());
				}
			}
		}
		cout << *max_element(ans.begin(), ans.end()) << endl;
		for(int i : ans)cout << i << ' ';
		cout << endl;
	}
}
