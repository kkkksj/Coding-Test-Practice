#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int ToInt(string time){
    string front = time.substr(0, 2);
    string back = time.substr(3);

    int ret = stoi(front) * 60 + stoi(back);

    return ret;
}

int solution(vector<vector<string>> book_time) {
    vector<pair<int, int>> books;

    for (auto book : book_time) {
        int start = ToInt(book[0]);
        int end = ToInt(book[1]) + 10;

        books.push_back({start, end});
    }

    sort(books.begin(), books.end());

    priority_queue<int, vector<int>, greater<int>> pq;

    for (auto book : books) {
        int start = book.first;
        int end = book.second;

        if (!pq.empty() && pq.top() <= start)
            pq.pop();

        pq.push(end);
    }

    return pq.size();
}