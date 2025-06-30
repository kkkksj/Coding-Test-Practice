#include <iostream>
#include <algorithm>
#include <map>
#include <stack>
#include <set>
using namespace std;

int HowConnected(map<int, stack<int>> &network, int node, set<int> &connected){
    while(network[node].empty() != 1){
        int tmp = network[node].top();
        network[node].pop();
        if(connected.find(tmp) == connected.end()){
            connected.insert(tmp);
            HowConnected(network, tmp, connected);
        }
    }
    return connected.size()-1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    
    map<int, stack<int>> network;
    set<int> connected;

    int a, b;
    for(int i=0; i<m; i++){
        cin >> a >> b;
        network[a].push(b);
        network[b].push(a);
    }

    connected.insert(1);
    cout << HowConnected(network, 1, connected);
}