#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	int n;cin >> n;
	string s;cin >> s;
	vector<int> ans;
	int curr = 0;
	for(int i = 0;i < n;i++){
		if(s[i] == 'B')curr++;
		else{
			if(curr > 0){
				ans.push_back(curr);
				curr = 0;
			}
		}
	}
	if(curr > 0)ans.push_back(curr);
	cout << ans.size() << endl;
	for(int i : ans)cout << i << ' ';
}
