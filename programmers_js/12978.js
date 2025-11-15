function PriorityQueue() {
  const heap = [];

  function swap(a, b) {
    [heap[a], heap[b]] = [heap[b], heap[a]];
  }

  function bubbleUp() {
    let i = heap.length - 1;

    while (i > 0) {
      let parent = Math.floor((i - 1) / 2);

      if (heap[parent][0] <= heap[i][0]) break;

      swap(i, parent);
      i = parent;
    }
  }

  function bubbleDown() {
    let i = 0;

    while (true) {
      let left = i * 2 + 1;
      let right = i * 2 + 2;
      let smallest = i;

      if (left < heap.length && heap[left][0] < heap[smallest][0]) {
        smallest = left;
      }

      if (right < heap.length && heap[right][0] < heap[smallest][0]) {
        smallest = right;
      }

      if (smallest === i) break;

      swap(i, smallest);
      i = smallest;
    }
  }

  return {
    push(item) {
      heap.push(item);
      bubbleUp();
    },

    pop() {
      if (heap.length === 1) return heap.pop();

      const top = heap[0];
      heap[0] = heap.pop();
      bubbleDown();

      return top;
    },

    isEmpty() {
      return heap.length === 0;
    },
  };
}
function dijkstra(start, graph, N) {
  const INF = Infinity;
  const dist = Array(N + 1).fill(INF);
  dist[start] = 0;

  const pq = PriorityQueue();
  pq.push([0, start]);

  while (!pq.isEmpty()) {
    const [curDist, cur] = pq.pop();

    if (curDist > dist[cur]) continue;

    for (let [next, cost] of graph[cur]) {
      const newDist = curDist + cost;

      if (newDist < dist[next]) {
        dist[next] = newDist;
        pq.push([newDist, next]);
      }
    }
  }

  return dist;
}

function solution(N, road, K) {
  const graph = Array(N + 1)
    .fill()
    .map(() => []);

  // 양방향 그래프
  for (let [a, b, cost] of road) {
    graph[a].push([b, cost]);
    graph[b].push([a, cost]);
  }

  // 다익스트라 실행
  const dist = dijkstra(1, graph, N);

  // K 이하인 마을 개수 세기
  return dist.filter((d) => d <= K).length;
}
