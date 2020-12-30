#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;cin >> n;
	string s;cin >> s;
	int cnt = 0;
	for(int i = 0;i < 1000;i++){
		string num = to_string(i);
		if(num.length() < 3){
			string t = string(3 - num.length(), '0');
			num = t + num;
		}
		size_t pos = -1;
		bool ans = true;
		for(int j = 0;j < 3;j++){
			pos = s.find(num[j], pos + 1);
			if(pos == string::npos)ans = false;
		}
		if(ans)cnt++;
	}
	cout << cnt << endl;
}
