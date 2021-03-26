#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long int ll;

int q(int fst, int snd, int trd){
	cout << fst << ' ' << snd << ' ' << trd << endl;
	int res;cin >> res;
	return res;
}

int main(){
	int t, n, qo;cin >> t >> n >> qo;
	while(t--){
		vector<int> ans;
		int frst = 1, send = 2, thrd = 3;
		int ress = q(frst, send, thrd);
		if(ress == 1)swap(frst, send);
		else if(ress == 3)swap(thrd, send);
		ans.push_back(frst);
		ans.push_back(send);
		ans.push_back(thrd);
		for(int i = 4;i <= n;i++){
			int l = 1;
			int r = ans.size() - 1;
			while(l <= r){
				int mid = l + (r - l) / 2;
				int fst = ans[mid - 1], snd = ans[mid], trd = i;
				int res = q(fst, snd, trd);	
				if(res == trd){
					ans.insert(ans.begin() + mid, i);
					break;
				}
				else if(res == fst){
					if(mid == l){
						ans.insert(ans.begin() + l - 1, i);
						break;
					}
					r = max(l, mid - 2);
				}
				else{
					if(mid == r){
						ans.insert(ans.begin() + r + 1, i);
						break;
					}
					l = min(r, mid + 2);
				}
			}
		}
		for(int i : ans)cout << i << ' ';
		cout << endl;
		int ver;cin >> ver;
		if(ver != 1)return 0;
	}
}

