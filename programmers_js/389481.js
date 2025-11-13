function solution(n, bans) {
  // 문자열을 숫자 인덱스로 변환 (a=1, b=2, …)
  const strToNum = (str) => {
    let num = 0;
    for (let ch of str) {
      num = num * 26 + (ch.charCodeAt(0) - "a".charCodeAt(0) + 1);
    }
    return num;
  };

  // 숫자 인덱스를 문자열로 변환
  const numToStr = (idx) => {
    let s = "";

    while (idx > 0) {
      let rem = (idx - 1) % 26;
      s = String.fromCharCode("a".charCodeAt(0) + rem) + s;
      idx = Math.floor((idx - 1) / 26);
    }
    return s;
  };

  // bans를 숫자 인덱스로 변환하고 정렬
  const banNums = bans.map(strToNum).sort((a, b) => a - b);

  let target = n;
  for (let bn of banNums) {
    if (bn <= target) {
      target++;
    } else {
      break;
    }
  }

  return numToStr(target);
}
