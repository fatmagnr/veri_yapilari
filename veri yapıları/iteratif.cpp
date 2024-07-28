#include <iostream>
#include <stack>
using namespace std;

struct Move {
    int disk;
    char from, to;
};

void hanoi_iterative(int n) {
    stack<Move> moves;
    char rods[3] = {'A', 'B', 'C'};
    int totalMoves = (1 << n) - 1; // 2^n - 1

    if (n % 2 == 0) {
        swap(rods[1], rods[2]);
    }

    for (int i = n; i > 0; --i) {
        moves.push({i, rods[0], rods[2]});
    }

    while (!moves.empty()) {
        Move move = moves.top();
        moves.pop();
        cout << "Move disk " << move.disk << " from " << move.from << " to " << move.to << endl;

        if (move.disk > 1) {
            moves.push({move.disk - 1, rods[1], rods[2]});
            moves.push({move.disk - 1, rods[0], rods[1]});
        }
    }
}
