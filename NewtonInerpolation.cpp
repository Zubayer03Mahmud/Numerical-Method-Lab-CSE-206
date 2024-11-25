#include<bits/stdc++.h>

using namespace std;

// Function to calculate the product term
float proterm(int i, float value, float x[]) {
    float pro = 1;
    for (int j = 0; j < i; j++) {
        pro *= (value - x[j]);
    }
    return pro;
}

// Function to calculate the divided difference table
void dividedDiffTable(float x[], float y[][10], int n) {
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n - i; j++) {
            y[j][i] = (y[j][i - 1] - y[j + 1][i - 1]) / (x[j] - x[i + j]);
        }
    }
}

// Function to apply Newton's divided difference formula
float applyFormula(float value, float x[], float y[][10], int n) {
    float sum = y[0][0];
    for (int i = 1; i < n; i++) {
        sum += proterm(i, value, x) * y[0][i];
    }
    return sum;
}

// Function to print the divided difference table
void printDiffTable(float y[][10], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i; j++) {
            cout << setprecision(4) << y[i][j] << "\t ";
        }
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Enter the number of data points: ";
    cin >> n;

    float x[10], y[10][10];
    cout << "Enter the x values:\n";
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }

    cout << "Enter the y values:\n";
    for (int i = 0; i < n; i++) {
        cin >> y[i][0];
    }

    dividedDiffTable(x, y, n);
    printDiffTable(y, n);

    float value;
    cout << "Enter the value to interpolate: ";
    cin >> value;

    cout << "\nValue at " << value << " is " << applyFormula(value, x, y, n) << endl;
    return 0;
}

