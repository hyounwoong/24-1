#include <iostream>
#include <vector>
#include<deque>
#include<iterator>
#include<algorithm>

using namespace std;

// N x N 크기의 2차원 배열을 만드는 함수
vector<vector<int>> createMap(int N) {

    vector<vector<int>> map(N, vector<int>(N, 0));

    for (int i = 0; i < N; ++i) {
        string row;
        cin >> row;

        for (int j = 0; j < N; ++j) {
            // 문자열을 정수로 변환하여 배열에 저장
            map[i][j] = row[j] - '0';
        }
    }

    return map;
}

void search(vector<vector<int>> map, int N ) {
    
    
    vector<bool> closed(N*N,false);
    vector<int> data;
    
  
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            //map[i][j]
            if (map[i][j] == 1 and closed[i*N+j]==false) {
                deque<int> open;
                

                open.push_back(i*N+j);
                int count = 1;
                closed[i * N + j]=true;
                
                
                while (!open.empty()) {
                    
                    int current = open.front();
                    open.pop_front();
                    
                    
                    
                    int a = current / N;
                    int b = current % N;
                    
                   
                    if (a + 1 != N   and closed[(a+1)*N+b]==false and map[a+1][b]==1) {
                        //open 안에 있는지 확인해야됨.
                        
                            auto it = std::find(open.begin(), open.end(), current + N);

                            if (it == open.end()) {
                                closed[current + N] = true;
                                open.push_back(current + N);
                                count++;
                            }
                        
                        

                    }
                    if (b + 1 != N  and closed[a*N+b+1]==false and map[a][b+1]==1 ) {
                        
                            auto it = std::find(open.begin(), open.end(), current + 1);
                            if (it == open.end()) {
                                closed[current + 1] = true;
                                open.push_back(current + 1);
                                count++;

                            }
                        
                        
                        
                    }
                    if (current >=N and  closed[current-N] == false and map[a-1][b] == 1) {
                        
                            auto it = std::find(open.begin(), open.end(), current - N);
                            if (it == open.end()) {
                                closed[current - N] = true;
                                open.push_back(current - N);
                                count++;
                            }
                        
                        
                    }
                    if (b>0 and closed[current - 1] == false and map[a][b-1] == 1) {
                        
                            auto it = std::find(open.begin(), open.end(), current - 1);
                            if (it == open.end()) {
                                closed[current - 1] = true;
                                open.push_back(current - 1);
                                count++;
                            }
                        
                        
                    }
                    


                }
                data.push_back(count);
                
               
                
                


            }
            
            
        }
        
    }
    std::cout << data.size()<<endl;
    std::sort(data.begin(), data.end());
    for (int child : data) {
        std::cout << child<<endl;
   }

}

int main() {
    int N;
    cin >> N;  // 지도의 크기 N

    // N x N 크기의 2차원 배열 생성
    vector<vector<int>> map = createMap(N);
    

    search(map,N);

    return 0;
    vector<int> T(4,4);


    
}