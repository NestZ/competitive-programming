#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	int t;cin >> t;
	for(int k = 0;k < t;k++){
		int row = 1;
		int col = 1;
		string s;cin >> s;
		string ans = "";
		stack<char> st;
		int n = s.length();
		for(int i = 0;i < n;i++){
			if(s[i] != ')')st.push(s[i]);
			else{
				string temp = "";
				while(st.top() != '('){
					temp.insert(temp.begin(), st.top());
					st.pop();
				}
				st.pop();
				int cnt = st.top() - '0';
				st.pop();
				string re = "";
				for(int j = 0;j < cnt;j++)re += temp;
				int l = re.length();
				for(int j = 0;j < l;j++)st.push(re[j]);
			}
		}
		vector<char> fi;
		while(!st.empty()){
			fi.push_back(st.top());
			st.pop();
		}
		reverse(fi.begin(), fi.end());
		for(char c : fi){
			if(c == 'N')row--;
			else if(c == 'S')row++;
			else if(c == 'E')col++;
			else col--;
			if(row == 0)row = 1000000000;
			if(col == 0)col = 1000000000;
			if(row == 1000000001)row = 1;
			if(col == 1000000001)col = 1;
		}
		cout << "Case #" << k + 1 << ": " << col << ' ' << row << endl;
	}
}
