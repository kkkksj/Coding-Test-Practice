#include <iostream>
#include <algorithm>
#include <vector>
#include <limits.h>

using namespace std;

int n;
int ans_max = INT_MIN;
int ans_min = INT_MAX;
void Combi(vector<int> &num_list, vector<int> &op_list, vector<int> &cal_op, vector<int> &used){
    if((int)cal_op.size() == n-1){
        int cal = num_list[0];
        for(int i=0; i<n-1; i++){
            int op;
            op = cal_op[i];
            if(op == 0)
                cal += num_list[i+1];
            else if(op == 1)
                cal -= num_list[i+1];
            else if(op == 2)
                cal *= num_list[i+1];
            else
                cal /= num_list[i+1];
        }
        ans_max = max(ans_max, cal);
        ans_min = min(ans_min, cal);
    }
    else{
        for(int i=0; i<n-1; i++)
            if(find(used.begin(), used.end(), i) == used.end()){
                cal_op.push_back(op_list[i]);
                used.push_back(i);
                Combi(num_list, op_list, cal_op, used);
                cal_op.pop_back();
                used.pop_back();
            }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;

    vector<int> num_list (n);
    for(int i=0; i<n; i++)
        cin >> num_list[i];
    
    vector<int> op_list;    // {0 : +, 1 : -, 2 : *, 3 : /}
    for(int i=0; i<4; i++){
        int num;
        cin >> num;
        for(int j=0; j<num; j++)
            op_list.push_back(i);
    }

    vector<int> cal_op;
    vector<int> used;
    Combi(num_list, op_list, cal_op, used);

    cout << ans_max << '\n' << ans_min << '\n';
}