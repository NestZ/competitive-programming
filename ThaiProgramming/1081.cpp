#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;cin >> n;
	vector<int> tl;
	vector<int> tr;
	vector<int> br;
	vector<int> bl;
	for(int i = 0;i < n;i++){
		for(int j = 0;j < n;j++){
			int num;cin >> num;
			if(i & 1){
				if(j & 1)br.push_back(num);
				else bl.push_back(num);
			}
			else{
				if(j & 1)tr.push_back(num);
				else tl.push_back(num);
			}
		}
	}
	sort(tl.begin(), tl.end());
	sort(tr.begin(), tr.end());
	sort(bl.begin(), bl.end());
	sort(br.begin(), br.end());
	int l = tl.size();
	int ans = 0;
	for(int i = 0;i < l;i++){
		ans += tl[i] * tr[i] * bl[i] * br[i];
	}
	cout << ans << endl;
}
