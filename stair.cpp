#include <iostream>
#include <vector>

const int MAX_STAIRS = 300;
const int MAX_SCORE = 10000;

std::vector<int> getStairsScores() {
    int numStairs;
    std::cin >> numStairs;

    if (numStairs <= 0 || numStairs > MAX_STAIRS) {
        std::cerr << "Invalid input: Number of stairs should be between 1 and " << MAX_STAIRS << "." << std::endl;
        exit(EXIT_FAILURE);
    }

    std::vector<int> stairsScores;
    for (int i = 0; i < numStairs; ++i) {
        int score;
        std::cin >> score;

        if (score < 0 || score > MAX_SCORE) {
            std::cerr << "Invalid input: Stair scores should be between 0 and " << MAX_SCORE << "." << std::endl;
            exit(EXIT_FAILURE);
        }

        stairsScores.push_back(score);
    }

    return stairsScores;
}


int calculate0(std::vector<int> abc, std::vector<std::vector<int>> data, int a) {
    if (a < 2) {
        return {};
    }
    int result;
    result = abc[a] + data[a - 1][1];




    return result;
}


int calculate1(std::vector<int> abc, std::vector<std::vector<int>> data, int a) {
    if (a < 2) {
        return {};
    }
    int result;
    result = abc[a] + data[a - 2][2];
    


    return result;
}

int  compareMax(int a, int b) {
   
    if (a >= b) {
        return a;
    }
    else
        return b;

}

int solveProblem(std::vector<int> abc) {
    
    int result; // 최댓값
    int size= abc.size(); //계단 개수
    if (size == 1) {
        return abc[0];
    }
    else if (size == 2) {
        return abc[0] + abc[1];
    }
    std::vector<std::vector<int>> data(size, std::vector<int>(3, 0));
    data[0][0] = abc[0];
    data[0][1] = abc[0];
    data[0][2] = abc[0];
    data[1][0] = abc[0] + abc[1];
    data[1][1] = abc[1];
    data[1][2] = abc[0] + abc[1];
    
    for (int i = 2; i < size; i++) {
        data[i][0]=  calculate0(abc,data, i);
        data[i][1]= calculate1(abc,data, i);
        data[i][2] = compareMax(data[i][0], data[i][1]);
    }
    result = data[size-1][2];
    return result;
}
int main() {
    
    std::vector<int> stairsScores = getStairsScores();
    
    int answer = solveProblem(stairsScores);
    std::cout << answer;

    

    return 0;
}

