#include <iostream>
#include <vector>
using namespace std;

void displayTowers(vector<vector<int>> &towers) {
    for (int i = towers[0].size() - 1; i >= 0; --i) {
        for (int j = 0; j < 3; ++j) {
            if (i < towers[j].size()) {
                cout << towers[j][i] << "\t";
            } else {
                cout << "|\t";
            }
        }
        cout << endl;
    }
    cout << "A\tB\tC" << endl << endl;
}

void moveDisk(vector<vector<int>> &towers, int from, int to) {
    int disk = towers[from].back();
    towers[from].pop_back();
    towers[to].push_back(disk);
    displayTowers(towers);
}

void hanoi_graphical(int n, int from, int to, int aux, vector<vector<int>> &towers) {
    if (n == 1) {
        moveDisk(towers, from, to);
        return;
    }
    hanoi_graphical(n - 1, from, aux, to, towers);
    moveDisk(towers, from, to);
    hanoi_graphical(n - 1, aux, to, from, towers);
}
