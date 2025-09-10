#include <iostream>
#include <fstream>
using namespace std;

int f1(int x) {
    if (x > 10)
        return 2 * x;
    else
        return -x;
}

int main() {
    ifstream fin("input.txt");   // đọc file input.txt
    if (!fin) {
        cout << "Khong mo duoc file input.txt\n";
        return 1;
    }

    int x;
    while (fin >> x) {   // đọc từng giá trị x trong file
        cout << "f1(" << x << ") = " << f1(x) << endl;
    }

    fin.close();
    return 0;
}
