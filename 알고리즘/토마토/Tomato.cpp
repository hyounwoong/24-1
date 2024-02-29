#include <iostream>
#include <vector>
#include<deque>
#include<iterator>
#include<algorithm>

using namespace std;


vector<vector<int>> createMap(int M,int N) {
    vector<vector<int>> map(N, vector<int>(M, 0));
    

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> map[i][j];
        }
    }

    return map;
}

void search(vector<vector<int>> map, int N, int M) {//N 행의개수=세로줄 개수,M 열의개수=가로줄 개수



    
    deque <vector<int>> open;
    int day = 0;
    int b = 0;
    int q = 0;
    

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (map[i][j] == 1) {
                vector<int> row = { i,j };
                open.push_back(row);
                q++;
                
            }
            else if (map[i][j] == -1) {
                b++;
            }


        }
    }
    while (!open.empty()) {

        int k = open.size();
        for (int i = 0; i < k; i++) {
            vector<int> current = open.front();
            open.pop_front();
            
                
                
                if (current[0] != N - 1 and map[current[0] + 1][current[1]] == 0) {

                    vector<int> T = { current[0] + 1,current[1] };
                   
                        open.push_back(T);
                        map[current[0] + 1][current[1]] = 1;
                        q++;


                    

                }
                if (current[1] != 0 and map[current[0]][current[1] - 1] == 0 ) {

                    vector<int> T = { current[0],current[1] - 1 };
                    
                        open.push_back(T);
                        map[current[0]][current[1] - 1] = 1;
                        q++;

                    

                }
                if (current[0] != 0 and map[current[0] - 1][current[1]] == 0 ) {

                    vector<int> T = { current[0] - 1,current[1] };
                    
                        open.push_back(T);
                        map[current[0] - 1][current[1]] = 1;
                        q++;

                    

                }
                if (current[1] != M - 1 and map[current[0]][current[1] + 1] == 0) {

                    vector<int> T = { current[0],current[1] + 1 };
                    
                        open.push_back(T);
                        map[current[0]][current[1] + 1] = 1;
                        q++;

                    

                }

            
        }
        day++;
    }
    if (q + b != N * M) {
        cout << -1;
    }
    else {
        cout << day - 1;
    }

}







int main() {
    int N,M;
    cin >> M>>N;  

  
    vector<vector<int>> map = createMap(M,N);
    
    search(map, N, M);
    

    return 0;
 }
