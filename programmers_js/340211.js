function solution(points, routes) {
  const n = points.length;
  const vis = new Map(); // 'r,c,time' 조합을 key로 사용

  for (let idx = 0; idx < routes.length; idx++) {
    const route = routes[idx];
    let time = 0;

    for (let i = 0; i < route.length - 1; i++) {
      let [r, c] = points[route[i] - 1];
      const [er, ec] = points[route[i + 1] - 1];

      // r 방향 이동
      while (r !== er) {
        const key = `${r},${c},${time}`;
        vis.set(key, (vis.get(key) || 0) + 1);
        r += r < er ? 1 : -1;
        time++;
      }

      // c 방향 이동
      while (c !== ec) {
        const key = `${r},${c},${time}`;
        vis.set(key, (vis.get(key) || 0) + 1);
        c += c < ec ? 1 : -1;
        time++;
      }
    }

    // 마지막 위치도 기록 (멈춘 자리)
    const key = `${er},${ec},${time}`;
    vis.set(key, (vis.get(key) || 0) + 1);
  }

  // 한 시각(t)에 같은 좌표(r,c)에 로봇 ≥ 2 → 충돌 위험
  let result = 0;
  for (const v of vis.values()) {
    if (v >= 2) result++;
  }

  return result;
}
