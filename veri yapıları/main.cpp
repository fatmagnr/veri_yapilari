#include <iostream>
#include <vector>
#include "iteratif.cpp"
#include "rekursif.cpp"
#include "grafikGosterimi.cpp"

using namespace std;

int main() {
    int choice, n;
    cout << "Enter the number of disks: ";
    cin >> n;

    cout << "Please choose an option:\n";
    cout << "1. Iterative method\n";
    cout << "2. Recursive method\n";
    cout << "Enter your choice: ";
    cin >> choice;

    vector<vector<int>> towers(3);
    for (int i = n; i > 0; --i) {
        towers[0].push_back(i);
    }
    displayTowers(towers);

    switch (choice) {
        case 1:
            hanoi_iterative(n);
            break;
        case 2:
            hanoi_recursive(n, 'A', 'C', 'B');
            break;
        default:
            cout << "Invalid choice!" << endl;
            return 1;
    }

    // Grafikte gösterim yapmak için tekrar başlat
    towers.clear();
    towers.resize(3);
    for (int i = n; i > 0; --i) {
        towers[0].push_back(i);
    }
    displayTowers(towers);
    hanoi_graphical(n, 0, 2, 1, towers);

    return 0;
}
