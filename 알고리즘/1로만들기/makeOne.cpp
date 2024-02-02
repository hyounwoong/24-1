// makeOne.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <algorithm>
int getInputInRange() {
    int num;
    while (true) {
        
        std::cin >> num;

        if (num >= 1 && num <= 1000000) {
            // 입력이 정상적이면 반복문 종료
            break;
        }
       
    }

    return num;
}





int main()
{
    int n = getInputInRange();
    if (n == 1) {
        std::cout << 0;
    }
    else if (n == 2 or n == 3) {
        std::cout << 1;
    }
    else {

        std::vector<int> data(n,0);
        data[0] = 0;
        data[1] = 1;
        data[2] = 1;
        for (int i = 3; i < n; i++) {
            int a,b;
            if ((i + 1) % 3 == 0) {
                a = data[((i + 1) / 3) - 1] + 1;

            }
            else
                a = 100;
            if ((i + 1) % 2 == 0) {
                b = data[((i + 1) / 2) - 1] + 1;

            }
            else
                b = 100;


            int min_value = std::min({ a,b,data[i-1]+1 });

            data[i] = min_value;


        }
        std::cout << data[n - 1];
    }
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
