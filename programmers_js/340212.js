function solution(diffs, times, limit) {
  let lo = 1;
  let hi = 100000;
  let result = hi;

  while (lo <= hi) {
    let mid_lv = Math.floor((lo + hi) / 2);
    let miss_match = false;
    let solve_time = 0;

    for (let i = 0; i < diffs.length; i++) {
      const time_cur = times[i];
      const time_prev = i === 0 ? 0 : times[i - 1];

      if (mid_lv < diffs[i]) { // 당신의 숙련도가 낮은 경우
        solve_time =
          solve_time + (time_cur + time_prev) * (diffs[i] - mid_lv) + time_cur;
      } else { // 당신의 숙련도가 같거나 높은 경우
        solve_time += time_cur;
      }

      if (solve_time > limit) {
        miss_match = true;
        break;
      }
    }

    if (miss_match) lo = mid_lv + 1;
    else {
      result = mid_lv;
      hi = mid_lv - 1;
    }
  }

  return result;
}
