function solution(numbers) {
    var answer = '';
    
    const numStr =  numbers.map(String)
    
    numStr.sort((a,b)=>(b+a) - (a+b))
    numStr.forEach((y)=>{
        answer += y
    })
    if(answer[0] === '0' ) answer = "0"
    return answer;
}