#include <iostream>
using namespace std;

void hanoi_recursive(int n, char from, char to, char aux) {
    if (n == 1) {
        cout << "Move disk 1 from " << from << " to " << to << endl;
        return;
    }
    hanoi_recursive(n - 1, from, aux, to);
    cout << "Move disk " << n << " from " << from << " to " << to << endl;
    hanoi_recursive(n - 1, aux, to, from);
}
