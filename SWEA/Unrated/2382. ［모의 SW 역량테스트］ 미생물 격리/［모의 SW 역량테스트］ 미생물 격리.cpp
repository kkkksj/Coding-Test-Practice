#include<iostream>
#include<vector>

using namespace std;

struct INFO {
    int i, j, num, dir;  // y좌표, x좌표, 미생물 수, 이동방향
};

vector<int> i_list = {0, -1, 1, 0, 0};
vector<int> j_list = {0, 0, 0, -1, 1};
vector<int> opposite = {0, 2, 1, 4, 3};

int n, m, k;
vector<INFO> micros;
vector<vector<int>> square;
vector<vector<int>> visited;

void Check4side(int i, int j){
    int max_num = -1;   // 합쳐지는 군집 중 최대의 미생물 수
    int max_micro = -1; // 대빵 군집 번호 
    for(int d=1; d<5; d++){
        int check_i = i+i_list[d];
        int check_j = j+j_list[d];
        int micro_number = square[check_i][check_j];
        if(micro_number == -1 || micros[micro_number].dir != opposite[d])
            continue;
        
        if(micros[micro_number].num > max_num){    // 미생물 수 체크
            max_num = micros[micro_number].num;

            if(max_micro != -1){    // 처음이 아니라면
                micros[micro_number].num += micros[max_micro].num;
                micros[max_micro].num = 0;  // 더 작은 애 죽이기
                square[micros[max_micro].i][micros[max_micro].j] = -1;
            }
    
            max_micro = micro_number;
        }
        else{
            micros[max_micro].num += micros[micro_number].num;

            micros[micro_number].num = 0;   // 더 작은 애 죽이기
            square[micros[micro_number].i][micros[micro_number].j] = -1;
        }
    }
}

void Move(){
    for(int t=0; t<k; t++){  // 일단 square에 깔기
        if(micros[t].num == 0)
            continue;
        square[micros[t].i][micros[t].j] = t;

        if(micros[t].i==0 || micros[t].j==0 || micros[t].i==n-1 || micros[t].j==n-1)
            micros[t].dir = opposite[micros[t].dir];
    }

    for(int t=0; t<k; t++){ // visited에 표시하기
        if(micros[t].num == 0)
            continue;
        int next_i = micros[t].i + i_list[micros[t].dir];
        int next_j = micros[t].j + j_list[micros[t].dir];

        visited[next_i][next_j] += 1;
    }

    for(int t=0; t<k; t++){ // 군집 수정하기
        
        if(micros[t].num == 0)
            continue;        

        int next_i = micros[t].i + i_list[micros[t].dir];
        int next_j = micros[t].j + j_list[micros[t].dir];

        if(visited[next_i][next_j] == 1){
            // 1. 가장 자리에 도착했을 때
            if(next_i == 0 || next_j == 0 || next_i == n-1 || next_j == n-1){
                micros[t].num /= 2;
            }
            square[micros[t].i][micros[t].j] = -1;  //수정 
            micros[t].i = next_i;
            micros[t].j = next_j;
        }

        else if(visited[next_i][next_j] > 1){   // 군집이 합쳐지는 경우
            Check4side(next_i, next_j);
            if(micros[t].num != 0){ // 대빵이라 살아남은 애라면 
                square[micros[t].i][micros[t].j] = -1;  //수정
                micros[t].i = next_i;
                micros[t].j = next_j;    
            }
        }
        else if(visited[next_i][next_j] == 0){
            square[micros[t].i][micros[t].j] = -1;  //수정 
            micros[t].i = next_i;
            micros[t].j = next_j;
        }

        visited[next_i][next_j] = 0;    // 수정
    }
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
	
	for(test_case = 1; test_case <= T; ++test_case)
	{
        cin >> n >> m >> k; // 한 변 길이, 격리 시간, 군집 개수
        micros.assign(k, {});
        square.assign(n, vector<int> (n, -1));
        visited.assign(n, vector<int> (n, 0));

        for(int t=0; t<k; t++){
            int i, j, num, dir;
            cin >> i >> j >> num >> dir;

            micros[t] = {i, j, num, dir};
        }
        
        while(m--)
            Move();
        

        int ans = 0;
        for(int t=0; t<k; t++)
            ans += micros[t].num;
        
        cout << '#' << test_case << ' ' << ans << '\n';
    }
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}