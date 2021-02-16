#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long int ll;

int get_code(int key, int c){
	int res = key + c - 1;
	if(res > 9)res -= 9;
	return res;
}

string turn(string key, string turn_key){
	int k0 = (turn_key[0] - '0') + (key[0] - '0');
	if(k0 > 9)k0 -= 9;
	key[0] = '0' + k0;
	int k1 = (key[1] - '0') - 1;
	if(k1 < 1)k1 += 9;
	key[1] = '0' + k1;
	int k2 = (turn_key[2] - '0') + (key[2] - '0');
	if(k2 > 9)k2 -= 9;
	key[2] = '0' + k2;
	return key;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string key;cin >> key;
	string turn_key = key;
	string code;cin >> code;
	int n = code.length();
	string ans = "";
	for(int i = 0;i < n;i++){
		int fst_code = get_code(key[0] - '0', code[i] - '0');
		int snd_code = get_code(key[1] - '0', fst_code);
		int trd_code = get_code(key[2] - '0', snd_code);
		key = turn(key, turn_key);
		ans += to_string(trd_code);
	}
	cout << ans << endl;
}
