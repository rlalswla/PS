function solution(participant, completion) {
    const hash = {};

    participant.forEach((people) => {
        if (hash[people]) {
            hash[people]++;
        } else {
            hash[people] = 1;
        }
    });

    completion.forEach((people) => {
        hash[people]--;
    });

    for (let key in hash) {
        if (hash[key] !== 0) return key;
    }
}
