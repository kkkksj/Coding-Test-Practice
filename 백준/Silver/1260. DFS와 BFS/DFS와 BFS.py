from collections import defaultdict
from collections import deque
import copy

n, m, v = map(int, input().split())

d = defaultdict(deque)

for i in range(m):
    n1, n2 = map(int, input().split())
    d[n1].append(n2)
    d[n2].append(n1)
    d[n1] = deque(sorted(d[n1]))
    d[n2] = deque(sorted(d[n2]))


def bfs(dic, point, visited_list):
    while len(dic[point]) != 0:
        node = dic[point].popleft()
        for i in range(len(dic[node])):
            add_node = dic[node].popleft()
            if add_node not in visited_list:
                dic[point].append(add_node)
        if node not in visited_list:
            visited_list.append(node)
    return visited_list


def dfs(dic, point, visited_list):
    while dic[point]:
        node = dic[point].popleft()
        if node not in visited_list:
            visited_list.append(node)
            dfs(dic, node, visited_list)

    return visited_list  # 모든 재귀 호출이 끝난 후 최종 리스트 반환

visited = [v]
d_copy = copy.deepcopy(d)
print(*dfs(d_copy, v, visited))

visited = [v]
print(*bfs(d, v, visited))
