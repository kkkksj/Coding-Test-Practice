#include <string>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

struct Plan {
    string name;
    int start;
    int playtime;
};

int ToMinute(string time) {
    int hour = stoi(time.substr(0, 2));
    int minute = stoi(time.substr(3, 2));

    return hour * 60 + minute;
}

bool cmp(Plan a, Plan b) {
    return a.start < b.start;
}

vector<string> solution(vector<vector<string>> plans) {
    vector<Plan> plan_list;

    for (auto plan : plans) {
        plan_list.push_back({
            plan[0],
            ToMinute(plan[1]),
            stoi(plan[2])
        });
    }

    sort(plan_list.begin(), plan_list.end(), cmp);

    vector<string> answer;
    stack<pair<string, int>> st;

    for (int i = 0; i < plan_list.size() - 1; i++) {
        string name = plan_list[i].name;
        int playtime = plan_list[i].playtime;

        int available = plan_list[i + 1].start - plan_list[i].start;

        if (playtime <= available) {
            answer.push_back(name);
            available -= playtime;

            while (!st.empty() && available > 0) {
                string pause_name = st.top().first;
                int remain = st.top().second;
                st.pop();

                if (remain <= available) {
                    answer.push_back(pause_name);
                    available -= remain;
                }
                else {
                    st.push({pause_name, remain - available});
                    available = 0;
                }
            }
        }
        else {
            st.push({name, playtime - available});
        }
    }

    answer.push_back(plan_list.back().name);

    while (!st.empty()) {
        answer.push_back(st.top().first);
        st.pop();
    }

    return answer;
}