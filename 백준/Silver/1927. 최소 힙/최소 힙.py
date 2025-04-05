from collections import deque
import sys
input = sys.stdin.readline

n = int(input())

heap = [0]

def make_min_heap(heap):
    index = len(heap) - 1
    while index > 1:
        parent_index = index // 2
        if heap[parent_index] > heap[index]:
            heap[parent_index], heap[index] = heap[index], heap[parent_index]
            index = parent_index
        else:
            break
    return heap

def sink_down(heap):
    index = 1
    while index * 2 < len(heap):
        if index*2 + 1 < len(heap):
            min_index = index*2 if heap[index*2] < heap[index*2+1] else index*2+1
            if heap[index] > heap[min_index]:
                heap[index], heap[min_index] = heap[min_index], heap[index]
                index = min_index
            else:
                break
        else:
            if heap[index] > heap[index*2]:
                heap[index], heap[index*2] = heap[index*2], heap[index]
                index = index*2
            else:
                break
    return heap

for i in range(n):
    x = int(input())
    if x == 0:
        if len(heap) != 1:
            heap[1], heap[-1] = heap[-1], heap[1]
            print(heap.pop())
            heap = sink_down(heap)
        else:
            print(0)
    else:
        heap.append(x)
        heap = make_min_heap(heap)
