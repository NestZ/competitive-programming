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
		bool ans = false;
		if(s == "2020")ans = true;
		else{
			for(int i = 0;i <= 4;i++){
				string fst = s.substr(0, i);
				string snd = s.substr(n - (4 - i), 4 - i);
				if(fst + snd == "2020")ans = true;
			}
		}
		if(ans)cout << "YES";
		else cout << "NO";
		cout << endl;
	}
}
