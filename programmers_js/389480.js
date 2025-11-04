function solution(info, n, m) {
  var answer = 121;
  const visited = new Set();
  const queue = [[0, 0, 0]];

  while (queue.length !== 0) {
    const [cur, a, b] = queue.pop();

    // 방문 상태 체크
    const key = `${cur}-${a}-${b}`;
    if (visited.has(key)) continue;
    visited.add(key);

    if (a >= n || b >= m) continue;
    if (cur == info.length) {
      // 마지막 물건까지 훔친 경우
      if (answer > a) answer = a; // 최소 흔적 개수 업데이트
      continue;
    }

    // 1. A가 물건을 훔치는 경우 = B가 물건을 훔치지 않는 경우
    queue.push([cur + 1, a + info[cur][0], b]);
    // 2. B가 물건을 훔치는 경우
    queue.push([cur + 1, a, b + info[cur][1]]);
  }

  return answer === 121 ? -1 : answer;
}
