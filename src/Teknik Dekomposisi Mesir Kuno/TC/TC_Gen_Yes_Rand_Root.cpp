#include <bits/stdc++.h>
using namespace std;

/*

Pilih jumlah node n secara acak.
Pilih node root secara acak.
Untuk setiap node i selain root, buat edge antara i dan root.
Acak urutan node sebelum mencetaknya.

*/

#include <bits/stdc++.h>
using namespace std;

/*

Pilih jumlah node n secara acak.
Pilih node root secara acak.
Untuk setiap node i selain root, buat edge antara i dan root.
Acak urutan node sebelum mencetaknya.

*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    srand(time(0));

    for (int t = 1; t <= 30; ++t) {
        ofstream fout("input" + to_string(t) + ".txt");

        
        int n = rand() % 100000 + 1;
        fout << n << "\n";

        // Generate nodes
        vector<int> nodes(n);
        for (int i = 0; i < n; ++i) {
            nodes[i] = i + 1;
        }

        // Shuffle nodes to create random edges
        random_shuffle(nodes.begin(), nodes.end());

        // Generate edges
        vector<int> rightNodes = nodes; // Save nodes that have not been used for the right segment
        for (int i = 0; i < n; ++i) {
            int leftNode = nodes[i];

            // Select a node that has not been used for the right segment
            int index = rand() % rightNodes.size();
            int rightNode = rightNodes[index];
            // Remove the node that has been used from the list of nodes that have not been used
            rightNodes.erase(rightNodes.begin() + index);

            fout << leftNode << " " << rightNode << "\n";
        }

        fout.close();
    }

    return 0;
}