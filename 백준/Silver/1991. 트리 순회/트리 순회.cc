#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <unordered_map>

using namespace std;

struct LR{
    char left;
    char right;
};

void VLR(unordered_map<char, LR> &tree_map, char root){
    cout << root;
    if(tree_map[root].left != '.')
        VLR(tree_map, tree_map[root].left);
    if(tree_map[root].right != '.')
        VLR(tree_map, tree_map[root].right);
}

void LVR(unordered_map<char, LR> &tree_map, char root){
    if(tree_map[root].left != '.')
        LVR(tree_map, tree_map[root].left);
    cout << root;
    if(tree_map[root].right != '.')
        LVR(tree_map, tree_map[root].right);    
}

void LRV(unordered_map<char, LR> &tree_map, char root){
    if(tree_map[root].left != '.')
        LRV(tree_map, tree_map[root].left);
    if(tree_map[root].right != '.')
        LRV(tree_map, tree_map[root].right);
    cout << root;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;

    char root, l, r;
    unordered_map<char, LR> tree_map;
    for(int i=0; i<n; i++){
        cin >> root >> l >> r;
        tree_map[root].left = l;
        tree_map[root].right = r;
    }

    VLR(tree_map, 'A');
    cout << '\n';
    LVR(tree_map, 'A');
    cout << '\n';
    LRV(tree_map, 'A');
}