function solution(targets) {
  let shot = -1;
  let answer = 0;

  targets.sort((a, b) => a[1] - b[1]);

  console.log(targets);
  targets.forEach((target, idx) => {
    if (target[0] > shot) {
      shot = target[1] - 1;
      answer++;
    }
  });

  return answer;
}
