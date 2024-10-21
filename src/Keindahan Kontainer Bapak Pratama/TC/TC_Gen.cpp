#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <random>
#include <ctime>
#include <cmath>

using namespace std;

int main() {
    srand(time(0));

    for (int t = 10; t <= 32; ++t) {
        ofstream fin("input" + to_string(t) + ".txt");
        ofstream fout("output" + to_string(t) + ".txt");

        int n = rand() % 49 + 2;
        int k = rand() % (int)(n * 0.7) + 1;
        fin << n << " ";
        fin << k << "\n";

        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<unsigned long long> dis(1, pow(2, 50));

        vector<unsigned long long> numbers;
        for (int i = 0; i < n; ++i) {
            unsigned long long num = dis(gen);
            while (find(numbers.begin(), numbers.end(), num) != numbers.end()) {
                num = dis(gen);
            }
            numbers.push_back(num);
        }

        // Mengacak urutan angka
        shuffle(numbers.begin(), numbers.end(), gen);

        for (int i = 0; i < n; ++i) {
            fin << numbers[i] << " ";
        }

        fin.close();
        fout.close();
    }

    return 0;
}