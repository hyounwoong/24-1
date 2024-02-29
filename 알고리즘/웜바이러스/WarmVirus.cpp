// WarmVirus.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include<set>
#include<deque>
#include<iterator>
#include<algorithm>
using namespace std;


struct Graph {
    vector<int> nodes;
    vector<set<int>> adjlist;
    void addNode(int a) {
        nodes.push_back(a);
        adjlist.resize(nodes.size());
    }


    void addEdge(int from, int to){
        adjlist[from-1].insert(to-1);
        adjlist[to-1].insert(from-1);
    }
    int search(int a) {//a-1번 노드부터 탐색시작(a-1번 노드의 값은 a)
        int count = 0;
        deque<int> open;
        vector<bool> closed(nodes.size(), false);
        open.push_back(a - 1);
        while (!open.empty()) {
            int n = open.front();
            open.pop_front();
            closed[n] = true;
            count = count + 1;
            if (adjlist[n].size() > 0) {
                for (auto child : adjlist[n]) {
                    auto k = find(open.begin(), open.end(), child);
                    if (k == open.end() and !closed[child]) {
                        open.push_back(child);
                    }
                }
            }




        }
        


        



        return count;
    }


};

int main()
{
    int a, b,c;
    Graph g;

    cin >> a;
    cin >> b;
    for (int i = 0; i < a; i++) {
        g.addNode(i+1);

    }
    for (int i = 0; i < b; i++) {
        int a, b;
        cin >> a >> b;
        g.addEdge(a, b);
    }
    int n = g.search(1);
    cout << n-1;
}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
