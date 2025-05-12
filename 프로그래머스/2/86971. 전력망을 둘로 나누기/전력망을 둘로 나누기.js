function solution(n, wires) {
    var answer = 100000000;
    const tree = [];
    for(let i = 0 ; i < n+1 ; i++){
        
        tree.push([]);
    }
    wires.forEach((item)=>{
        tree[item[0]].push(item[1])
        tree[item[1]].push(item[0])
    })
    console.log(tree)
    const bfs = (first, second) =>{
        const q = [first];
        const visited = new Array(n+1).fill(false)
        let cnt=0;
        visited[first] = true;
        while(!(q.length === 0)){
            const now = q[0]
            cnt++;
            q.shift();
            tree[now].forEach((next)=>{
                if(visited[next] === false && !(now === first && next === second)){
                    q.push(next);
                    visited[next] = true;
                }
            })
        }
       return cnt;
    }
    
    wires.forEach((edge)=>{
        const first = edge[0]
        const second = edge[1]
        const ret = bfs(first, second);
        let other = n-ret;
        console.log(ret, other)
        answer = Math.min(Math.abs(ret-other), answer);
    })
    return answer;
}