// 모든 조합 생성
function getCombination(n) {
  const results = [];

  function combination(num, cnt, arr) {
    if (cnt === 5) {
      results.push([...arr]);
      return;
    }

    for (let i = num; i <= n; i++) {
      arr.push(i);
      combination(i + 1, cnt + 1, arr);
      arr.pop();
    }
  }

  combination(1, 0, []);
  return results;
}

function solution(n, q, ans) {
  let combi = getCombination(n);

  q.forEach((query, idx) => {
    const querySet = new Set(query);

    combi = combi.filter((arr) => {
      let match = 0;

      for (let num of arr) {
        if (querySet.has(num)) match++;
      }

      return ans[idx] === match;
    });
  });

  return combi.length;
}

/*
1~n까지의 서로 다른 정수 5개의 모든 조합 만들기 - 백트래킹
만든 조합과 입력한 정수를 비교해서 일치하는 개수가 동일한 경우 - 비밀코드로 가능
*/
