#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;cin >> n;
	int state = 1;
	string res = "";
	vector<string> code;
	for(int i = 0;i < n;i++){
		string s;
		cin >> s;
		if(s.length() == 16)
			code.push_back(s);
	}
	for(string s : code){
		int asc = 0;
		for(int i = 0;i < 8;i++){
			string cur = s.substr(i * 2, 2);
			if(state == 1){
				if(cur == "11"){
					asc += (1 << (8 - i - 1));
					state = 2;
				}
			}
			else if(state == 2){
				if(cur == "10"){
					state = 3;
				}
				else if(cur == "01"){
					asc += (1 << (8 - i - 1));
					state = 4;
				}
			}
			else if(state == 3){
				if(cur == "00"){
					asc += (1 << (8 - i - 1));
					state = 2;
				}
				else if(cur == "11"){
					state = 1;
				}
			}
			else{
				if(cur == "10"){
					asc += (1 << (8 - i - 1));
				}
				else if(cur == "01"){
					state = 3;
				}
			}
		}
		res += char(asc);
	}
	cout << res << endl;
}
