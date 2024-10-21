#include <bits/stdc++.h>
using namespace std;

/*

Pilih jumlah node n secara acak.
Pilih node root secara acak.
Untuk setiap node i selain root, buat edge antara i dan root.
Acak urutan node sebelum mencetaknya.

*/

int main() {
    srand(time(0));

    for (int t = 1; t <= 1; ++t) {
        ofstream fin("input" + to_string(t) + ".txt");
        ofstream fout("output" + to_string(t) + ".txt");

        // int n = rand() % 100000 + 1;
        int n = 50000;
        fin << n << "\n";

        vector<int> nodes(n);
        iota(nodes.begin(), nodes.end(), 1);
        random_shuffle(nodes.begin(), nodes.end());

        int root = nodes[0]; // select the first node as root after shuffling

        for (int i = 1; i < n; i++) {
            fin << root << " " << nodes[i] << "\n";
        }

        fin.close();
        fout.close();
    }

    return 0;
}