#include <iostream>
using namespace std;

int findMax(int num1, int num2, int num3) {
    int max = 0;
    if ((num1 > num2) && (num1 > num3)) max = num1;
    if ((num2 > num1) && (num2 > num3)) max = num2;
    if ((num3 > num1) && (num3 > num2)) max = num3;
    return max;
}

int main() {
    // Danh sách test-case
    int tests[6][3] = {
        {5, 3, 1},    // TC1
        {5, 5, 3},    // TC2
        {7, 7, 7},    // TC3
        {-1, -2, -3}, // TC4
        {2, 9, 4},    // TC5
        {3, 6, 10}    // TC6
    };

    for (int i = 0; i < 6; i++) {
        int a = tests[i][0], b = tests[i][1], c = tests[i][2];
        cout << "TC" << (i+1) 
             << " Input(" << a << "," << b << "," << c << ")"
             << " -> Output: " << findMax(a,b,c) << endl;
    }

    return 0;
}
