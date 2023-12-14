#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
int M, Cnt=0;
string num;
vector<pair<int, int>> V;
int arr[10][10];
int row[10][10], col[10][10], box[10][10];
int Box_num(int i, int j) {
  if (i <= 3 && j <= 3)
    return 1;
  else if (i <= 3 && j <= 6)
    return 2;
  else if (i <= 3 && j <= 9)
    return 3;
  else if (i <= 6 && j <= 3)
    return 4;
  else if (i <= 6 && j <= 6)
    return 5;
  else if (i <= 6 && j <= 9)
    return 6;
  else if (i <= 9 && j <= 3)
    return 7;
  else if (i <= 9 && j <= 6)
    return 8;
  else if (i <= 9 && j <= 9)
    return 9;
  return -1;
}
void Sudoku(int cnt) {
  if ( cnt == M && Cnt == 0 ) {
    // 스도쿠 완성!
    for (int i = 1; i <= 9; i++) {
      for (int j = 1; j <= 9; j++)
        cout << arr[i][j];
      cout << '\n';
    }
    Cnt = 1;
    exit(0); // 프로그램 종료
  }

  int cur_i = V[cnt].first;
  int cur_j = V[cnt].second;

  for (int j = 1; j <= 9; j++) {
    int box_num = Box_num(cur_i, cur_j);
    if (!row[cur_i][j] && !col[cur_j][j] && !box[box_num][j]) {
      row[cur_i][j] = 1;
      col[cur_j][j] = 1;
      box[box_num][j] = 1;
      arr[cur_i][cur_j] = j;

      Sudoku(cnt + 1);

      row[cur_i][j] = 0;
      col[cur_j][j] = 0;
      box[box_num][j] = 0;
      arr[cur_i][cur_j] = 0;
    }
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  for (int i = 1; i <= 9; i++) {
    cin >> num;
    for (int j = 1; j <= 9; j++) {
      arr[i][j] = (int)(num[j-1]-'0');

      if (arr[i][j] > 0) {
        row[i][arr[i][j]] = 1;
        col[j][arr[i][j]] = 1;
        box[Box_num(i, j)][arr[i][j]] = 1;
      }
      else {
        V.push_back({i, j});
        M++;
      }
    }
  }

  Sudoku(0);
}

/*
가로, 세로, 9칸 use배열
row[9][10], col[9][10], box[9][3][3]
있는 숫자는 1표시
*/