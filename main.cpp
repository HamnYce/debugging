#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <fstream>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <math.h>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
using namespace std;
#define INFILE FILE *in = fopen("main.in", "r");
#define OUTFILE FILE *out = fopen("main.out", "w");
#define INCIN ifstream cin("main.in");
#define OUTCOUT ofstream cout("main.out");
#define pii pair<int, int>
#define ll long long
#define ull unsigned long long

int main() {
  int n = 0, m = 0, k = 0, startX = 0, startY = 0, total = 0, bug = 0;

  cin >> n >> m >> k;

  char maze[505][505];
  bool visited[505][505];

  memset(visited, false, sizeof visited);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> maze[i][j];

      if (maze[i][j] == '.') {
        total++;
        startX = i;
        startY = j;
      }
    }
  }

  total -= k;
  stack<pii> s;
  s.push({startX, startY});

  while (!s.empty()) {
    pii v = s.top();
    s.pop();
    total--;
    if (total < 1) {
      maze[v.first][v.second] = 'X';
      bug++;
    }
    vector<pii> moves;

    visited[v.first][v.second] = true;

    moves.push_back({v.first, v.second - 1});
    moves.push_back({v.first, v.second + 1});
    moves.push_back({v.first - 1, v.second});
    moves.push_back({v.first + 1, v.second});

    for (pii move : moves) {
      if (move.first > -1 && move.first < n && move.second > -1 &&
          move.second < m && (maze[move.first][move.second] == '.') &&
          !visited[move.first][move.second]) {
        s.push(move);
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cout << maze[i][j];
    }
    cout << endl;
  }
  cout << bug;
  return 0;
}
