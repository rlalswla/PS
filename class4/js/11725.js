const fs = require("fs");
const input = fs.readFileSync("./input.txt").toString().trim().split("\n");

const solution = () => {
  const N = Number(input[0]);
  const graph = Array.from({ length: N + 1 }, () => []);
  const parent = Array(N + 1).fill(-1);
  for (let i = 1; i < N; i++) {
    const [a, b] = input[i].split(" ").map(Number);
    graph[a].push(b);
    graph[b].push(a);
  }
  dfs(1, graph, parent);

  parent.slice(2).forEach((input) => console.log(input));
};

const dfs = (index, graph, parent) => {
  graph[index].forEach((element) => {
    if (parent[element] === -1) {
      parent[element] = index;
      dfs(element, graph, parent);
    }
  });
};

solution();
