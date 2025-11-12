function getStartTime(task) {
  const [h, m] = task[1].split(":").map(Number);
  return h * 60 + m;
}

function solution(plans) {
  let queue = [];
  let answer = [];

  plans.sort((a, b) => a[1].localeCompare(b[1]));

  for (let i = 0; i < plans.length; i++) {
    const curTime = getStartTime(plans[i]);
    const nextTime = i !== plans.length - 1 ? getStartTime(plans[i + 1]) : 1540;
    const playtime = Number(plans[i][2]);

    if (curTime + playtime > nextTime) {
      // 현재 과제를 다 못 끝낼 경우
      // 남은 과제 시간 계산해서 큐에 저장
      queue.push([plans[i][0], curTime + playtime - nextTime]);
    } else {
      // 시간이 같거나 남는 경우
      answer.push(plans[i][0]);

      let leftTime = nextTime - (curTime + playtime); // 남은 시간

      while (leftTime > 0) {
        const prevTask = queue.pop();
        if (!prevTask) break;

        if (prevTask[1] <= leftTime) {
          answer.push(prevTask[0]);
          leftTime = leftTime - prevTask[1];
        } else {
          queue.push([prevTask[0], prevTask[1] - leftTime]);
          break;
        }
      }
    }
  }

  // 큐에 남아있는 과목도 추가해주기 ( 최근 멈춘 순서 )
  return answer.concat(queue.reverse().map((e) => e[0]));
}
