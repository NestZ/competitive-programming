/*
ID: nestz
LANG: C++14
TASK: namenum
*/
#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("namenum.out", "w", stdout);
	freopen("namenum.in", "r", stdin);
	
	vector<string> srl(8);
	srl[0] = "ABC";
	srl[1] = "DEF";
	srl[2] = "GHI";
	srl[3] = "JKL";
	srl[4] = "MNO";
	srl[5] = "PRS";
	srl[6] = "TUV";
	srl[7] = "WXY";
	ifstream dict;
	dict.open("dict.txt");
	string serial;cin >> serial;
	int n = serial.length();
	string curr;
	vector<string> ans;
	while(getline(dict, curr)){
		if(curr.length() != n)continue;
		bool can = true;
		for(int i = 0;i < n;i++){
			int num = serial[i] - '0';
			string possible = srl[num - 2];
			if(possible.find(curr[i]) == string::npos)can = false;
		}
		if(can)ans.push_back(curr);
	}
	if(ans.size() == 0)cout << "NONE" << endl;
	else{
		for(string s : ans)cout << s << endl;
	}
}
