#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;cin >> s;
	string want = "keyence";
	bool ans = false;
	for(int i = 0;i < 8;i++){
		string fst_w = want.substr(0, i);
		string snd_w = want.substr(i, 7 - i);
		string fst_s = s.substr(0, i);
		string snd_s = s.substr(s.length() - snd_w.length(), snd_w.length());
		if(i == 0){
			if(snd_w == snd_s)ans = true;
		}
		else if(i == 7){
			if(fst_w == fst_s)ans = true;
		}
		else{
			if(fst_w == fst_s && snd_w == snd_s)ans = true;
		}
	}
	if(ans)cout << "YES";
	else cout << "NO";
	cout << endl;
}
