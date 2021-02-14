#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;cin >> n >> m;
	bool valid = true;
	map<char, int> cnt;
	for(int i = 0;i < n;i++){
		for(int j = 0;j < m;j++){
			char c;cin >> c;
			cnt[c]++;
		}
	}
	int four = (n / 2) * (m / 2);
	for(char c = 'a';c <= 'z';){
		if(four == 0)break;
		if(cnt[c] >= 4){
			cnt[c] -= 4;
			four--;
		}
		else c++;
	}
	if(four > 0)valid = false;
	int two = (n / 2 * (m & 1)) + (m / 2 * (n & 1));
	for(char c = 'a';c <= 'z';){
		if(two == 0)break;
		if(cnt[c] >= 2){
			cnt[c] -= 2;
			two--;
		}
		else c++;
	}
	if(two > 0)valid = false;
	int sum = 0;
	for(auto p : cnt)sum += p.second;
	if((n & 1) && (m & 1)){
		if(sum != 1)valid = false;
	}
	else{
		if(sum != 0)valid = false;
	}
	if(valid)cout << "Yes";
	else cout << "No";
	cout << endl;
}
