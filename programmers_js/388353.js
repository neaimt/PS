function solution(storage, requests) {
  const n = storage.length;
  const m = storage[0].length;

  let vis = Array.from({ length: n }).map(() => Array(m).fill(0));
  var queue = [];

  function bfs(req) {
    const dx = [0, 1, 0, -1];
    const dy = [1, 0, -1, 0];

    // 접근 가능한 공간일 경우 큐에 넣기
    for (let i = -1; i <= n; i++) {
      for (let j = -1; j <= m; j++) {
        if (i == -1 || i == n || j == -1 || j == m) {
          queue.push([i, j]);
        } else if (vis[i][j] == 1) queue.push([i, j]);
      }
    }

    // 접근 가능한 공간 상하좌우에 특정 컨테이너가 있으면 꺼냄
    while (queue.length !== 0) {
      const [curX, curY] = queue.shift(); // pop()으로 써도 ok ( 더 빠름 )

      for (let dir = 0; dir < 4; dir++) {
        const nx = curX + dx[dir];
        const ny = curY + dy[dir];

        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
        if (vis[nx][ny] == 1) continue;

        if (storage[nx][ny] == req) {
          // 지게차 작업 접근 가능 공간 표시
          vis[nx][ny] = 1;
        }
        if (vis[nx][ny] == 2) {
          // 크레인 작업 후 접근 가능 공간 표시
          vis[nx][ny] = 1;
          queue.push([nx, ny]);
        }
      }
    }
  }

  requests.forEach((req) => {
    if (req.length == 1) bfs(req);
    else {
      for (let i = 0; i < n; i++) {
        for (let j = 0; j < m; j++) {
          if (storage[i][j] == req[0]) {
            vis[i][j] = 2;
          }
        }
      }
    }
  });

  return vis.flat().filter((num) => num === 0).length;
}

/*
지게차로 컨테이너를 꺼내는 경우 - 접근 가능한 컨테이너만 제거
크레인으로 컨테이너를 꺼내는 경우 - 해당 컨테이너 제거 후 접근 가능 공간인지 확인

100 * 50 * 50 
*/
