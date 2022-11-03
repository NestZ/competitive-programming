#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int ll;

#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for(auto it = d.b;it != d.e;++it)
    *this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

bool check(vector<vector<int>> a, vector<vector<int>> b, int r, int c) {
  for (int i = 0;i < r;i++) {
    for (int j = 0;j < c;j++) {
      if (a[i][j] != b[i][j]) return false;
    }
  }
  return true;
}

void fill(vector<vector<int>> *a, int i, int j, int w, bool unfill, int n, int m) {
  if (i < 0 || i >= n || j < 0 || j >= m) return;
  for (int ii = i;ii < i + w;ii++) {
    for (int jj = j;jj < j + w;jj++) {
      if (!unfill) (*a)[ii][jj] = 1;
      else (*a)[ii][jj] = 0;
    }
  }
}

void reset(vector<vector<int>> *a, int n, int m) {
  for (int i = 0;i < n;i++) {
    for (int j = 0;j < m;j++) {
      (*a)[i][j] = 0;
    }
  }
}

void print(vector<vector<int>> a, int r, int c) {
  for (int i = 0;i < r;i++) {
    for (int j = 0;j < c;j++) {
      cout << a[i][j];
    }
    cout << endl;
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;cin >> n >> m;
  vector<vector<int>> board(n + 1, vector<int>(m + 1));
  int fr = -1, fc = -1;
  for (int i = 0;i < n;i++) {
    for (int j = 0;j < m;j++) {
      char c;cin >> c;
      if (c == '.') board[i][j] = 0;
      else board[i][j] = 1;
      if (board[i][j] == 1 && fr == -1) {
        fc = j;
        fr = i;
      }
    }
  }

  int cur_cnt = 0;
  for (int i = fc;i < m;i++) {
    if (board[fr][i] == 1) cur_cnt++;
    else break;
  }
  int fw = cur_cnt;
  cur_cnt = 0;
  for (int i = fr;i < n;i++) {
    if (board[i][fc] == 1) cur_cnt++;
    else break;
  }
  fw = min(fw, cur_cnt);

  cout << fr + 1 << ' ' << fc + 1 << ' ' << fw << endl;

  vector<vector<int>> board2(n + 1, vector<int>(m + 1));
  for (int i = 0;i < n;i++) {
    for (int j = 0;j < m;j++) {
      board2[i][j] = board[i][j];
    }
  }
  fill(&board2, fr, fc, fw, true, n, m);

  int fr2 = -1, fc2 = -1;
  int lr = -1, lc = -1;
  for (int i = 0;i < n;i++) {
    for (int j = 0;j < m;j++) {
      if (board2[i][j] != 0) {
        if (fr2 == -1) {
          fr2 = i;
          fc2 = j;
        }
        lr = i;
        lc = j;
      }
    }
  }
  if (lr == -1) {
    cout << fr + 1 << ' ' << fc + 1 << ' ' << 1 << endl;
    return 0;
  }

  cur_cnt = 0;
  for (int i = fr2;i < n;i++) {
    if(board2[i][fc2] == 1) cur_cnt++;
    else break;
  }
  int lw = cur_cnt;
  cur_cnt = 0;
  for (int i = fc2;i < m;i++) {
    if (board2[fr2][i] == 1) cur_cnt++;
    else break;
  }
  lw = max(lw, cur_cnt);
  //test fill
  reset(&board2, n, m);
  fill(&board2, fr, fc, fw, false, n, m);
  fill(&board2, lr - lw + 1, lc - lw + 1, lw, false, n, m);
  if (check(board, board2, n, m)) {
    cout << lr - lw + 2 << ' ' << lc - lw + 2 << ' ' << lw << endl;
    return 0;
  }
  reset(&board2, n, m);

  fill(&board2, fr, fc, fw, false, n, m);
  fill(&board2, fr2, fc2, lw, false, n, m);
  if (check(board, board2, n, m)) {
    cout << fr2 + 1 << ' ' << fc2 + 1 << ' ' << lw << endl;
    return 0;
  }
}
