#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int parent[101];

int find(int x) {
    if (parent[x] == x) {
        return x;
    }
    return parent[x] = find(parent[x]); 
}

void Union(int a, int b) {
    a = find(a);
    b = find(b);
    
    if(a!=b)
        parent[b] = a;
}

bool isConnected(int a, int b) {
    return find(a) == find(b);
}

int solution(int n, vector<vector<int>> costs) {
    for (int i = 0; i < n; i++) 
        parent[i] = i;
    
    sort(costs.begin(), costs.end(), [](vector<int>& a, vector<int>& b) {
        return a[2] < b[2];  
    });
    
    int answer = 0;
    int edgeCount = 0; 
    
    for (vector<int>& cost : costs) {
        int island1 = cost[0];
        int island2 = cost[1];
        int price = cost[2];
        
        if (!isConnected(island1, island2)) {
            Union(island1, island2); 
            answer += price;
            edgeCount++;
            
            if (edgeCount == n - 1)
                break;
        }
    }
    
    return answer;
}