#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

char table[8][8] = {{'.', '.', '.', '.', '.', '.', '.', '.'},
				  {'.', '.', '.', '.', '.', '.', '.', '.'},
				  {'.', '.', '.', '.', '.', '.', '.', '.'},
				  {'.', '.', '.', 'O', 'X', '.', '.', '.'},
				  {'.', '.', '.', 'X', 'O', '.', '.', '.'},
				  {'.', '.', '.', '.', '.', '.', '.', '.'},
				  {'.', '.', '.', '.', '.', '.', '.', '.'},
				  {'.', '.', '.', '.', '.', '.', '.', '.'}};
				  
bool valid(int i, int j){
	if(i >= 8 || i < 0 || j >= 8 || j < 0)return false;
	return true;
}

vector<pair<int, int>> rem;

void eat(int i, int j,int a, int b, char opp, char curr){
	vector<pair<int, int>> del;
	for(int k = 1;valid(i + k * a, j + k * b);k++){
		char currT = table[i + k * a][j + k * b];
		if(currT == opp)
			del.push_back({i + k * a, j + k * b});
		else if(currT == curr){
			for(auto p : del)rem.push_back(p);
			return;
		}
		else return;
	}
}

int main(){
	char c[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};
	int turn = 0;
	char t[2] = {'X', 'O'};
	map<char, int> col;
	for(int i = 1;i <= 8;i++)col[c[i - 1]] = i;
	int k;cin >> k;
	for(int i = 0;i < k;i++){
		char m;cin >> m;
		int n;cin >> n;
		int trow = n - 1;
		int tcol = col[m] - 1;
		char opp = t[(turn + 1) & 1];
		char curr = t[turn & 1];
		table[trow][tcol] = curr;
		eat(trow, tcol, 0, 1, opp, curr);
		eat(trow, tcol, 0, -1, opp, curr);
		eat(trow, tcol, 1, 0, opp, curr);
		eat(trow, tcol, -1, 0, opp, curr);
		eat(trow, tcol, 1, 1, opp, curr);
		eat(trow, tcol, 1, -1, opp, curr);
		eat(trow, tcol, -1, 1, opp, curr);
		eat(trow, tcol, -1, -1, opp, curr);
		for(auto p : rem)table[p.first][p.second] = curr;
		rem.clear();
		turn++;
	}
	for(int i = 0;i < 8;i++){
		for(int j = 0;j < 8;j++){
			cout << table[i][j];
		}
		cout << endl;
	}
}
