const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");

const solution = () => {
  const N = Number(input[0]);

  // 2차원 배열 초기화 (26개의 노드 가정 - A부터 Z까지)
  const tree = Array.from({ length: 26 }, () => Array(2).fill("."));

  for (let i = 1; i <= N; i++) {
    const line = input[i].split(" ");
    const nodeIndex = line[0].charCodeAt(0) - "A".charCodeAt(0); // A를 0으로 변환

    tree[nodeIndex][0] = line[1]; // 왼쪽 자식
    tree[nodeIndex][1] = line[2]; // 오른쪽 자식
  }

  // 순회 함수 구현
  const preorder = (node) => {
    if (node === ".") return "";

    const nodeIndex = node.charCodeAt(0) - "A".charCodeAt(0);
    let result = node;
    result += preorder(tree[nodeIndex][0]); // 왼쪽 자식
    result += preorder(tree[nodeIndex][1]); // 오른쪽 자식

    return result;
  };

  const inorder = (node) => {
    if (node === ".") return "";

    const nodeIndex = node.charCodeAt(0) - "A".charCodeAt(0);
    let result = inorder(tree[nodeIndex][0]); // 왼쪽 자식
    result += node;
    result += inorder(tree[nodeIndex][1]); // 오른쪽 자식

    return result;
  };

  const postorder = (node) => {
    if (node === ".") return "";

    const nodeIndex = node.charCodeAt(0) - "A".charCodeAt(0);
    let result = postorder(tree[nodeIndex][0]); // 왼쪽 자식
    result += postorder(tree[nodeIndex][1]); // 오른쪽 자식
    result += node;

    return result;
  };

  // 순회 결과 출력
  console.log(preorder("A"));
  console.log(inorder("A"));
  console.log(postorder("A"));
};

solution();
