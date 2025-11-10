function solution(land) {
  let num = 1;
  let result = Array(land[0].length).fill(0);
  let queue = [];
  let vis = Array.from({ length: land.length }, () =>
    Array(land[0].length).fill(0)
  );

  // 석유 집합 탐색
  const DFS = (i, j) => {
    let cnt = 0;
    let ny_idx = new Set();
    const dx = [0, 1, -1, 0];
    const dy = [1, 0, 0, -1];

    vis[i][j] = 1;
    queue.push([i, j]);
    ny_idx.add(j);

    while (queue.length !== 0) {
      const [curX, curY] = queue.pop();
      cnt++;

      for (let dir = 0; dir < 4; dir++) {
        const nx = curX + dx[dir];
        const ny = curY + dy[dir];

        if (nx < 0 || nx >= land.length || ny < 0 || ny >= land[0].length)
          continue;
        if (vis[nx][ny] !== 0 || land[nx][ny] !== 1) continue;

        vis[nx][ny] = 1;
        queue.push([nx, ny]);
        ny_idx.add(ny);
      }
    }

    return [cnt, ny_idx]; // 석유 집합의 크기, 석유가 있는 열 인덱스들
  };

  for (let i = 0; i < land.length; i++) {
    for (let j = 0; j < land[0].length; j++) {
      if (land[i][j] === 1 && vis[i][j] === 0) {
        const [cnt, ny_idx] = DFS(i, j);

        for (const ny of ny_idx) {
          result[ny] += cnt;
        }
      }
    }
  }

  return Math.max(...result);
}
