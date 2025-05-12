function solution(nums) {
    var answer = 0;
    const s = new Set();
    nums.forEach((it)=>{
        s.add(it);
    })
    const si = s.size
    return Math.min(nums.length/2 , si);
}