def solution(answers):
    answer = []
    one = [1,2,3,4,5]
    two = [2,1,2,3,2,4,2,5]
    three = [3,3,1,1,2,2,4,4,5,5]
    
    correct = [0, 0, 0, 0]
    for i in range(len(answers)):
        if one[i%5] == answers[i]:
            correct[1] += 1
        if two[i%8] == answers[i]:
            correct[2] += 1
        if three[i%10] == answers[i]:
            correct[3] += 1
    score = []
    for i in range(3):
        max_idx = correct.index(max(correct))
        if not answer or score[-1] == correct[max_idx]:
            answer.append(max_idx) 
            score.append(correct[max_idx])
            correct[max_idx] = 0
        else:
            break
    return answer