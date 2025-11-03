function solution(players, m, k) {
  const server = Array(24).fill(0); // 시각별 서버 수
  var answer = 0;

  players.forEach((user_cnt, time) => {
    if (user_cnt >= m) {
      // 이용자 수가 m 이상일 경우, 서버 증설
      const need = Math.floor(user_cnt / m); // 필요한 서버 개수
      let update_server = 0; // 증설한 서버 개수

      if (server[time] < need) update_server = need - server[time];

      answer += update_server;

      for (let i = time; i < time + k && i < 24; i++) {
        // 정해진 시간동안 켜져있는 서버
        server[i] += update_server;
      }
    }
  });

  return answer;
}

// 서버를 증설할 경우 - server 배열에 k시간만큼 서버 개수 충당
