function solution(n, w, num) {
  const m = Math.ceil(n / w);
  let arr = Array.from({ length: m }).map(() =>
    Array.from({ length: w }).fill(0)
  );
  let k = 1;
  let num_idx = [];
  let answer = 0;

  for (let i = 0; i < m; i++) {
    if (i % 2 == 0) {
      // 오른쪽 방향
      for (let j = 0; j < w; j++) {
        arr[i][j] = k++;
        if (k === num + 1) num_idx.push(i, j);
      }
    } else {
      // 왼쪽 방향
      for (let j = w - 1; j >= 0; j--) {
        arr[i][j] = k++;
        if (k === num + 1) num_idx.push(i, j);
      }
    }
  }

  for (let i = num_idx[0]; i < m; i++) {
    if (arr[i][num_idx[1]] !== 0 && arr[i][num_idx[1]] <= n) answer++;
  }

  return answer;
}
