function solution(picks, minerals) {
  const maxMinerals = (picks[0] + picks[1] + picks[2]) * 5;
  const available = minerals.slice(0, maxMinerals);
  const n = available.length;

  const arr = [];

  for (let i = 0; i < n; i += 5) {
    const mineral = available.slice(i, Math.min(i + 5, n));
    arr.push([
      mineral.filter((e) => e === "diamond").length,
      mineral.filter((e) => e === "iron").length,
      mineral.filter((e) => e === "stone").length,
    ]);
  }

  arr.sort(
    (a, b) => b[0] * 25 + b[1] * 5 + b[2] - (a[0] * 25 + a[1] * 5 + a[2])
  );

  let answer = 0;
  let cur = 0;

  // 다이아몬드
  for (let i = 0; i < picks[0] && cur < arr.length; i++, cur++) {
    answer += arr[cur][0] + arr[cur][1] + arr[cur][2];
  }

  // 철
  for (let i = 0; i < picks[1] && cur < arr.length; i++, cur++) {
    answer += arr[cur][0] * 5 + arr[cur][1] + arr[cur][2];
  }

  // 돌
  for (let i = 0; i < picks[2] && cur < arr.length; i++, cur++) {
    answer += arr[cur][0] * 25 + arr[cur][1] * 5 + arr[cur][2];
  }

  return answer;
}
