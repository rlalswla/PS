function solution(citations) {
    let cnt =0;
    citations.sort((a,b)=>b-a)
    
    citations.forEach((h,i)=>{
        
        if(h < i+1) return cnt;
        else cnt++;
    })
    return cnt;
}