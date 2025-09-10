#include <iostream>
#include <fstream>
using namespace std;

int f2(int x) { if (x < 10)
return 2 * x; else if (x < 2)
return -x; else
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
        cout << "f2(" << x << ") = " << f2(x) << endl;
    }

    fin.close();
    return 0;
}
