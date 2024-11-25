#include<bits/stdc++.h>
using namespace std;

// Function to perform Gauss-Jordan Elimination
void gaussJordan(vector<vector<double>>& matrix) {
    int n = matrix.size();

    for (int i = 0; i < n; i++) {
        // Pivot row
        int pivot = i;
        for (int j = i + 1; j < n; j++) {
            if (abs(matrix[j][i]) > abs(matrix[pivot][i]))
                pivot = j;
        }
        swap(matrix[i], matrix[pivot]);

        // Make the diagonal elements 1
        double divisor = matrix[i][i];
        for (int j = 0; j < n + 1; j++) {
            matrix[i][j] /= divisor;
        }

        // Make the other elements in the column zero
        for (int j = 0; j < n; j++) {
            if (j != i) {
                double multiplier = matrix[j][i];
                for (int k = 0; k < n + 1; k++) {
                    matrix[j][k] -= multiplier * matrix[i][k];
                }
            }
        }
    }
}

// Function to display the solutions
void displaySolutions(const vector<vector<double>>& matrix) {
    int n = matrix.size();
    cout << "Solutions:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "x" << i + 1 << " = " << matrix[i][n] << endl;
    }
}

int main() {
    int n;
    cout << "Enter the number of equations: ";
    cin >> n;

    vector<vector<double>> matrix(n, vector<double>(n + 1, 0));

    cout << "Enter the augmented matrix:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n + 1; j++) {
            cin >> matrix[i][j];
        }
    }

    gaussJordan(matrix);

    displaySolutions(matrix);

    return 0;
}
