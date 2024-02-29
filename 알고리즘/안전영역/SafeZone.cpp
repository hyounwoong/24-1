#include <iostream>
#include <vector>
#include<queue>
#include<iterator>
#include<algorithm>
#include<stack>

using namespace std;

// N x N 크기의 2차원 배열을 만드는 함수
vector<vector<int>> createMap(int N) {

    vector<vector<int>> map(N, vector<int>(N, 0));

    for (int i = 0; i < N; ++i) {
        

        for (int j = 0; j < N; ++j) {
            // 문자열을 정수로 변환하여 배열에 저장
            cin >> map[i][j];
        }
    }

    return map;
}
void search(vector<vector<int>> map, int N) {
    
    stack<vector<int>> open;
    bool factor = true;
    int rain = 0;
    int bignum = 0;
    int safezone = 0;
    
    
    
    int dx[4] = { -1, 0, 1, 0 };
    int dy[4] = { 0, 1, 0, -1 };

    while (factor == true) {
        int zone = 0;
        vector<vector<bool>> closed(N, vector<bool>(N, false));
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (map[i][j] > rain and closed[i][j] == false) {
                    open.push({ i,j });
                    closed[i][j] = true;

                    while (!open.empty()) {
                        vector<int> current = open.top();
                        open.pop();
                        for (int k = 0; k < 4; k++) {
                            int xx = current[0] + dx[k];
                            int yy = current[1] + dy[k];
                            if (0 <= xx and xx < N and 0 <= yy and yy<N and map[xx][yy] >rain and closed[xx][yy] == false) {
                                open.push({ xx,yy });
                                closed[xx][yy] = true;
                            }
                        }//dx dy


                    }//while open
                    zone=zone+1;
                }//조사

                bignum = max(bignum, map[i][j]);
            }//이중
        }//이중
        
        safezone = max(zone, safezone);
        if (rain ==bignum) {
            
            factor = false;

        }
        rain++;
    }//팩터트루
   
    cout << safezone;


}//함수


    


int main()
{
    int N;
    cin >> N;
    vector<vector<int>>  map = createMap(N);
    search(map, N);
}


