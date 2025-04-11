text = list(input())
bomb = list(input())

stack = []
for char in text:
    stack.append(char)
    if stack[len(stack)-len(bomb):] == bomb:
        for i in range(len(bomb)):
            stack.pop()
if stack:
    print(*stack, sep="")
else:
    print("FRULA")