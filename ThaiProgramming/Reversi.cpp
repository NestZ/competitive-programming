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

int dx[] = {1, 0, 1, -1, -1, 0, -1, 1};
int dy[] = {0, 1, 1, -1, 0, -1, 1, -1};
vector<pair<int, int>> rem;
bool eated = false;

void eat(int row, int col,int cur_dx, int cur_dy, char opp, char cur, bool start){
	if(table[row][col] == '.')return;
	if(start){
		if(valid(row + cur_dx, col + cur_dy)){
			eat(row + cur_dx, col + cur_dy, cur_dx, cur_dy, opp, cur, false);
		}
	}
	else{
		if(table[row][col] == opp)rem.push_back({row, col});
		else if(table[row][col] == cur){
			for(int i = 0;i < (int)rem.size();i++){
				int fst = rem[i].first;
				int snd = rem[i].second;
				table[fst][snd] = cur;
				eated = true;
			}
			return;
		}
		if(valid(row + cur_dx, col + cur_dy)){
			eat(row + cur_dx, col + cur_dy, cur_dx, cur_dy, opp, cur, false);
		}
	}
}

int main(){
	int k;cin >> k;
	char sym[] = {'X', 'O'};
	int turn = 0;
	for(int i = 0;i < k;i++, turn = (turn + 1) % 2){
		char c;cin >> c;
		int col = c - 'a';
		int row;cin >> row; row--;
		table[row][col] = sym[turn];
		for(int j = 0;j < 8;j++){
			eat(row, col, dx[j], dy[j], sym[(turn + 1) % 2], sym[turn], true);
			rem = vector<pair<int, int>>();
		}
		if(!eated){
			turn = (turn + 1) % 2;
			table[row][col] = sym[turn];
			for(int j = 0;j < 8;j++){
				eat(row, col, dx[j], dy[j], sym[(turn + 1) % 2], sym[turn], true);
				rem = vector<pair<int, int>>();
			}
		}
		eated = false;
	}

	for(int i = 0;i < 8;i++){
		for(int j = 0;j < 8;j++){
			cout << table[i][j];
		}
		cout << endl;
	}
}
