#include <iostream>
#include <vector>

using namespace std;

vector<int> tree;

int IsThere(int n){
    if(tree[n] == n)
        return n;
    return tree[n] = IsThere(tree[n]);
}

void Uni(int a, int b){
    int root1 = IsThere(a);
    int root2 = IsThere(b);

    if(root1 != root2)
        tree[root1] = root2;
    else
        return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n, m;
    cin >> n >> m;

    tree.resize(n+1);
    for(int i=0; i<n+1; i++)
        tree[i] = i;

    while(m--){
        int c, a, b;
        cin >> c >> a >> b;

        if(c == 0)
            Uni(a, b);
        else{
            if(IsThere(a) == IsThere(b))
                cout << "YES" << '\n';
            else
                cout << "NO" << '\n';
        }
    }
}