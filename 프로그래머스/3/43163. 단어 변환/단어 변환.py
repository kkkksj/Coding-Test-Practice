from collections import deque

def IsOnly1Diff(a, b):
    n = len(a)
    diff = 0
    for i in range(n):
        if a[i] != b[i]:
            diff += 1
    if diff == 1:
        return True
    return False

def solution(begin, target, words):
    words_n = len(words)
    visited = [False] * words_n
    q = deque()
    q.append([begin, 0])
    
    while q:
        now_word, cnt = q.popleft()
        if now_word == target:
            return cnt
        
        for i in range(words_n):
            if visited[i] == True:
                continue
            next_word = words[i]
            if IsOnly1Diff(now_word, next_word):
                visited[i] = True
                q.append([next_word, cnt+1])
        
    return 0