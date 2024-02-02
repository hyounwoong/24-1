#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int search(int root, int compare) {
    queue<int> q;
    vector<bool> visited(compare + 1, false);

    q.push(root);
    visited[root] = true;
    int distance = 0;

    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; ++i) {
            int node = q.front();
            q.pop();

            if (node == compare) {
                return distance;
            }

            if (node - 1 > 0 && !visited[node - 1]) {
                q.push(node - 1);
                visited[node - 1] = true;
            }
            if (node + 1 <= compare && !visited[node + 1]) {
                q.push(node + 1);
                visited[node + 1] = true;
            }
            if (node * 2 <= compare && !visited[node * 2]) {
                q.push(node * 2);
                visited[node * 2] = true;
            }
        }

        ++distance;
    }

    return -1; // compare가 root로부터 도달할 수 없을 때
}

int main() {
    int n, k;
    cin >> n >> k;
    cout << search(n, k);

}