#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;

    int one, two, three;
    cin >> one >> two >> three;

    int max1=one, max2=two, max3=three;
    int min1=one, min2=two, min3=three;

    for (int i=1; i<n; i++) {
        cin >> one >> two >> three;

        int pre_max1=max1, pre_max2=max2, pre_max3=max3;
        int pre_min1=min1, pre_min2=min2, pre_min3=min3;

        max1 = one + max(pre_max1, pre_max2);
        max2 = two + max({pre_max1, pre_max2, pre_max3});
        max3 = three + max(pre_max2, pre_max3);

        min1 = one + min(pre_min1, pre_min2);
        min2 = two + min({pre_min1, pre_min2, pre_min3});
        min3 = three + min(pre_min2, pre_min3);
    }

    cout << max({max1, max2, max3}) << ' ' << min({min1, min2, min3}) << '\n';
}