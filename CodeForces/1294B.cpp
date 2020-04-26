#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;cin >> t;
	while(t--){
		int n;cin >> n;
		vector<pair<int, int>> arr;
		for(int i = 0;i < n;i++){
			int x, y;cin >> x >> y;
			arr.push_back({x, y});
		}
		sort(arr.begin(), arr.end());
		vector<char> ans;
		bool flag = true;
		int currx = 0;
		int curry = 0;
		for(pair<int, int> p : arr){
			if(p.second < curry){
				flag = false;
				break;
			}
			for(int i = 0;i < p.first - currx;i++)ans.push_back('R');
			currx = p.first;
			for(int i = 0;i < p.second - curry;i++)ans.push_back('U');
			curry = p.second;
		}
		if(flag){
			cout << "YES" << endl;
			for(char c : ans)cout << c;
			cout << endl;
		}
		else cout << "NO" << endl;
	}
}
