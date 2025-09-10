#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>
#include <algorithm>
using namespace std;

int solveQuartic(double a, double b, double c, double x[]) {
    if (a == 0 && b == 0 && c == 0) {
        return -1;
    }
    if (a == 0 && b == 0) {
        return 0;
    }

    if (a == 0) {
        double y = -c / b;
        if (y < 0) return 0;
        x[0] = sqrt(y);
        x[1] = -sqrt(y);
        return 2;
    }

    double delta = b * b - 4 * a * c;
    if (delta < 0) return 0;

    double y1 = (-b + sqrt(delta)) / (2 * a);
    double y2 = (-b - sqrt(delta)) / (2 * a);

    int count = 0;
    if (y1 >= 0) {
        x[count++] = sqrt(y1);
        x[count++] = -sqrt(y1);
    }
    if (y2 >= 0 && y2 != y1) {
        x[count++] = sqrt(y2);
        x[count++] = -sqrt(y2);
    }

    return count;
}

// Hàm test
void runTest(double a, double b, double c, vector<double> expected, string name) {
    double x[4];
    int n = solveQuartic(a, b, c, x);

    cout << name << ": ";
    if (n == -1 && expected.empty()) {
        cout << "PASS (Infinite solutions)" << endl;
        return;
    }
    if (n == 0 && expected.empty()) {
        cout << "PASS (No solution)" << endl;
        return;
    }

    vector<double> actual(x, x+n);
    if (actual.size() != expected.size()) {
        cout << "FAIL (size mismatch)" << endl;
        return;
    }
    // So sánh từng nghiệm (có thể dùng sai số epsilon)
    sort(actual.begin(), actual.end());
    sort(expected.begin(), expected.end());
    double eps = 1e-6;
    for (size_t i=0; i<expected.size(); i++) {
        if (fabs(actual[i] - expected[i]) > eps) {
            cout << "FAIL" << endl;
            return;
        }
    }
    cout << "PASS" << endl;
}

int main() {
    runTest(0,0,0, {}, "TC1");
    runTest(0,0,5, {}, "TC2");
    runTest(0,2,-8, {2,-2}, "TC3");
    runTest(1,0,-9, {sqrt(3),-sqrt(3)}, "TC4");
    runTest(1,-5,4, {1,-1,2,-2}, "TC5");
    runTest(1,2,5, {}, "TC6");
    return 0;
}
