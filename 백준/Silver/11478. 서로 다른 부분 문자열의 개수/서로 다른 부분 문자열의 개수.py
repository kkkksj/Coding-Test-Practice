word = input()
n = len(word)
diff = set()

for i in range(n):
    for j in range(i+1, n+1):
        diff.add(word[i:j])
print(len(diff))