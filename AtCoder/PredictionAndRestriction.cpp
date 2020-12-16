#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int r, p, s;
int point(char c){
	if(c == 'r')return p;
	else if(c == 'p')return s;
	else return r;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, k;cin >> n >> k;
	cin >> r >> s >> p;
	string st;cin >> st;
	vector<string> arr(k, "");
	for(int i = 0;i < n;i++){
		arr[i % k] += st[i];
	}
	int ans = 0;
	for(string str : arr){
		int len = str.length();
		if(len == 0)continue;
		ans += point(str[0]);
		bool can = false;
		for(int i = 1;i < len;i++){
			if(str[i] != str[i - 1]){
				ans += point(str[i]);
				can = false;
			}
			else{
				if(can)ans += point(str[i]);
				can = !can;
			}
		}
	}
	cout << ans << endl;
}
