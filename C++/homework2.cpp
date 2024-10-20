#include <iostream>
#include <vector>
#include <set>
#include <string>
using namespace std;

bool isMagicSquare(const vector<vector<int>>& matrix, int n, int magicSum) {
    for (int i = 0; i < n; ++i) {
        int rowSum = 0, colSum = 0;
        for (int j = 0; j < n; ++j) {
            rowSum += matrix[i][j];
            colSum += matrix[j][i];
        }
        if (rowSum != magicSum || colSum != magicSum) return false;
    }
    int diag1Sum = 0, diag2Sum = 0;
    for (int i = 0; i < n; ++i) {
        diag1Sum += matrix[i][i];
        diag2Sum += matrix[i][n - 1 - i];
    }
    return diag1Sum == magicSum && diag2Sum == magicSum;
}

bool solveMagicSquare(vector<vector<int>>& matrix, int n, vector<pair<int, int>>& missing, set<int>& used) {
    if (missing.empty()) {
        int magicSum = 0;
        for (int j = 0; j < n; ++j) magicSum += matrix[0][j];
        return isMagicSquare(matrix, n, magicSum);
    }

    auto [row, col] = missing.back();
    missing.pop_back();

    for (int num = 0; num <= n^2; ++num) {
        if (used.count(num)) continue;
        matrix[row][col] = num;
        used.insert(num);
        if (solveMagicSquare(matrix, n, missing, used)) return true;
        used.erase(num);
    }

    missing.push_back({row, col});
    return false;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> matrix(n, vector<int>(n));
    vector<pair<int, int>> missing;
    set<int> used;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            string input;
            cin >> input;
            if (input == "_") {
                missing.push_back({i, j});
            } else {
                int num = stoi(input);
                matrix[i][j] = num;
                used.insert(num);
            }
        }
    }

    if (solveMagicSquare(matrix, n, missing, used)) {
        for (const auto& row : matrix) {
            for (int i = 0; i < n; ++i) {
                if (i > 0) cout << " ";
                cout << row[i];
            }
            cout << endl;
        }
    } else {
        cout << "No solution" << endl;
    }

    return 0;
}
