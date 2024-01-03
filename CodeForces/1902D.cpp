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

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, q;cin >> n >> q;
  string s;cin >> s;

  int cur_x = 0;
  int cur_y = 0;
  map<pair<int, int>, vector<int>> m;
  set<pair<int, int>> all_pos;
  vector<pair<int, int>> arr(n + 1);
  arr[0] = {0, 0};
  all_pos.insert({0, 0});

  m[{0, 0}].push_back(0);

  for (int i = 1;i <= n;i++) {
    if (s[i - 1] == 'R') {
      cur_x++;
    } else if (s[i - 1] == 'L') {
      cur_x--;
    } else if (s[i - 1] == 'U') {
      cur_y++;
    } else {
      cur_y--;
    }
    all_pos.insert({cur_x, cur_y});
    arr[i] = {cur_x, cur_y};

    m[{cur_x, cur_y}].push_back(i);
  }

  vector<pair<pair<int, int>, pair<int, int>>> new_pos;
  vector<pair<int, int>> lr;
  while(q--) {
    int x, y, l, r;cin >> x >> y >> l >> r;
    lr.push_back({l, r});

    int left = min(arr[l - 1].first, arr[r].first);
    int right = max(arr[l - 1].first, arr[r].first);
    int up = max(arr[l - 1].second, arr[r].second);
    int down = min(arr[l - 1].second, arr[r].second);

    if (x == 0 && y == 0) {
      new_pos.push_back({{0, 0}, {0, 0}});
      continue;
    }

    int new_x = right - (x - left);
    int new_y = up - (y - down);

    new_pos.push_back({{new_x, new_y}, {x, y}});
  }

  for (int i = 0;i < new_pos.size();i++) {
    int new_x = new_pos[i].first.first;
    int new_y = new_pos[i].first.second;
    int old_x = new_pos[i].second.first;
    int old_y = new_pos[i].second.second;

    int l = lr[i].first;
    int r = lr[i].second;
    bool ok = false;

    if (m.count({new_x, new_y}) > 0) {
      auto it = lower_bound(m[{new_x, new_y}].begin(), m[{new_x, new_y}].end(), l);
      if (*it < r && it != m[{new_x, new_y}].end()) {
        ok = true;
      }
    }

    if (m.count({old_x, old_y}) > 0) {
      auto it = lower_bound(m[{old_x, old_y}].begin(), m[{old_x, old_y}].end(), 0);
      if (*it <= l - 1 && it != m[{old_x, old_y}].end()) {
        ok = true;
      }
    }

    if (m.count({old_x, old_y}) > 0) {
      auto it = lower_bound(m[{old_x, old_y}].begin(), m[{old_x, old_y}].end(), r);
      if (*it <= n && it != m[{old_x, old_y}].end()) {
        ok = true;
      }
    }

    if (ok) cout << "YES" << endl;
    else cout << "NO" << endl;
  }
}
