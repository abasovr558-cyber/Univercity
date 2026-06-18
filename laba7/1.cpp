#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> generateBoard(const vector<int>& queensPositions, int n) {
    vector<string> board(n, string(n, '.'));
    for (int row = 0; row < n; ++row) {
        board[row][queensPositions[row]] = 'Q';
    }
    return board;
}

void solve(int currentRow, int n, vector<int>& queensPositions,
    vector<bool>& columnOccupied, vector<bool>& diag1Occupied, vector<bool>& diag2Occupied,
    vector<vector<string>>& solutions, bool& foundAny) {

    if (currentRow == n) {
        solutions.push_back(generateBoard(queensPositions, n));
        foundAny = true;
        return;
    }

    for (int col = 0; col < n; ++col) {
        if (foundAny) return;

        int d1 = currentRow - col + n;
        int d2 = currentRow + col;

        if (columnOccupied[col] || diag1Occupied[d1] || diag2Occupied[d2]) {
            continue;
        }

        queensPositions[currentRow] = col;
        columnOccupied[col] = diag1Occupied[d1] = diag2Occupied[d2] = true;

        solve(currentRow + 1, n, queensPositions, columnOccupied, diag1Occupied, diag2Occupied, solutions, foundAny);

        columnOccupied[col] = diag1Occupied[d1] = diag2Occupied[d2] = false;
    }
}

int main() {
    int n;
    if (!(cin >> n)) return 0;

    vector<int> queensPositions(n);
    vector<bool> columnOccupied(n, false);
    vector<bool> diag1Occupied(2 * n, false);
    vector<bool> diag2Occupied(2 * n, false);

    vector<vector<string>> solutions;
    bool foundAny = false;

    solve(0, n, queensPositions, columnOccupied, diag1Occupied, diag2Occupied, solutions, foundAny);

    if (solutions.empty()) {
        cout << "Решений нет" << endl;
        return 0;
    }

    for (size_t i = 0; i < solutions.size(); ++i) {
        cout << "[" << endl;
        for (int row = 0; row < n; ++row) {
            cout << " \"" << solutions[i][row] << "\"";
            if (row < n - 1) cout << "," << endl;
            else cout << endl;
        }
        cout << "]" << endl;
    }

    return 0;
}
