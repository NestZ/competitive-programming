#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s1, s2;cin >> s1 >> s2;
	int sx = s1[0] - 'a' + 1;
	int sy = s1[1] - '0';
	int dx = s2[0] - 'a' + 1;
	int dy = s2[1] - '0';
	vector<string> ans;
	while(sx < dx && sy < dy){
		sx++;
		sy++;
		ans.push_back("RU");
	}
	while(sx > dx && sy > dy){
		sx--;
		sy--;
		ans.push_back("LD");
	}
	while(sx > dx && sy < dy){
		sx--;
		sy++;
		ans.push_back("LU");
	}
	while(sx < dx && sy > dy){
		sx++;
		sy--;
		ans.push_back("RD");
	}
	while(sx > dx){
		sx--;
		ans.push_back("L");
	}
	while(sy > dy){
		sy--;
		ans.push_back("D");
	}
	while(sx < dx){
		sx++;
		ans.push_back("R");
	}
	while(sy < dy){
		sy++;
		ans.push_back("U");
	}
	cout << ans.size() << endl;
	for(string t : ans)cout << t << endl;
}
