#include <bits/stdc++.h>
using namespace std;

int main() {
    srand(time(0));

    for (int t = 1; t <= 2; ++t) {
        ofstream fin("input" + to_string(t) + ".txt");
        ofstream fout("output" + to_string(t) + ".txt");

        int n = rand() % 100000 + 1;
        fin << n << "\n";

        for (int i = 1; i < n; i++) {
            int a = rand() % i;
            int b = i;
            fin << a + 1 << " " << b + 1 << "\n";
        }

        fin.close();
        fout.close();
    }

    return 0;
}