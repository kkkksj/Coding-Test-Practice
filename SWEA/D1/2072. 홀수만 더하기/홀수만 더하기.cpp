#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    
	int test_case;
	int T;
    int num;
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
        int ans = 0;
        for(int i=0; i<10; i++){
            cin >> num;
            if(num % 2 == 1)
                ans += num;
        }
        cout << '#' << test_case << ' ' << ans << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}