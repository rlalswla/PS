const fs = require("fs");
const input = fs.readFileSync("./input.txt").toString().trim().split("\n");

const divsqu = (a, b, c) => {
  if (b === 0) return 1;
  if (b === 1) return a % c;

  const half = divsqu(a, Math.floor(b / 2), c);
  let res = (half * half) % c;
  if (b % 2 === 1) res = ((res * a) % c) % c;
  return res;
};

const solution = () => {
  let [a, b, c] = input[0].split(" ").map(Number);

  console.log(divsqu(a, b, c));
};

solution();
