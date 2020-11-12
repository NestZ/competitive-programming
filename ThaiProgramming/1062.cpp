#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int maslen, len;cin >> maslen >> len;
	string mas1, mas2, key;cin >> mas1 >> mas2 >> key;
	string ans = "";
	for(int i = 0;i < len;i++){
		string cur = "";
		cur += key[i];
		for(int j = 0;j < maslen;j++){
			cur += mas1[j];
			cur += mas2[j];
			sort(cur.begin(), cur.end());
			char t = cur[1];
			cur = "";
			cur += t;
		}
		ans += cur;
	}
	cout << ans << endl;
}
