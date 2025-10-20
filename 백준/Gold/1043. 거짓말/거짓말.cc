#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
int k;
vector<int> parent;

int find_p(int num){
    if(num != parent[num])
        return parent[num] = find_p(parent[num]);
    else
        return parent[num];
}

void Union(int a, int b){
    int pa = find_p(parent[a]);
    int pb = find_p(parent[b]);

    if(pa != pb){
        if(pa < pb)
            parent[pb] = parent[pa];
        else
            parent[pa] = parent[pb];
    }
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL);

    cin >> n >> m;

    parent.assign(n+1, 0);
    for(int i=1; i<n+1; i++)
        parent[i] = i;

    cin >> k;
    for(int i=0; i<k; i++){
        int num;
        cin >> num;
        parent[num] = 0;
    }

    int Pnum;
    int temp;
    int temp2;
 
    int arr[53][53]; 
    int arrsiz[53]; 
    for(int i =0;i<m;i++){
        cin >> Pnum;
        cin >> temp; 
        arrsiz[i] = Pnum; 
        arr[i][0] =temp; 
        for(int j = 1; j < Pnum; j++){
            cin >> temp2; 
            arr[i][j] = temp2;
            Union(temp ,temp2); 
        }
    }
    int answer = m;
    
    for(int i =0; i<m;i++){
        for(int j=0;j<arrsiz[i]; j++){
            if(find_p(parent[arr[i][j]]) == 0){
                answer--;
                break;
            }
        }
    }
    cout << answer << '\n';
}