#include <iostream>
#include <fstream>
#include <cmath> 
using namespace std;

int f3(int x) {
if (log(x * x * cos(x)) < 3 * x) return 2 * x;
else
return 2 * x;
}

int main() {
    ifstream fin("input.txt");   // đọc file input.txt
    if (!fin) {
        cout << "Khong mo duoc file input.txt\n";
        return 1;
    }

    int x;
    while (fin >> x) {   // đọc từng giá trị x trong file
        cout << "f3(" << x << ") = " << f3(x) << endl;
    }

    fin.close();
    return 0;
}
