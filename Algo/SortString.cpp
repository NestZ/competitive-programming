#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;cin >> t;
	while(t--){
		int n, k;cin >> n >> k;
		int fst = n - 2, snd = n - 1;
		for(int i = 0;i < k - 1;i++){
			if(fst + 1 == snd){
				fst--;
				snd = n - 1;
			}
			else snd--;
		}
		for(int i = 0;i < n;i++){
			if(i == fst || i == snd)cout << 'b';
			else cout << 'a';
		}
		cout << endl;
	}
}
