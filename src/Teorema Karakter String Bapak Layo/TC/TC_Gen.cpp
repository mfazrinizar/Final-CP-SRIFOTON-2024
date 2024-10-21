#include <fstream>
#include <cstdlib>
#include <ctime>

int main() {
    srand(time(0));

    for (int i = 0; i < 32; ++i) {
        std::string filename = "input" + std::string(i < 10 ? "0" : "") + std::to_string(i) + ".txt";
        std::ofstream out(filename);

        long long k;
        int t;

        // For the last two test cases, test the boundary conditions
        if (i == 30) {
            k = 1;
            t = 1;
        } else if (i == 31) {
            k = 2e9;
            t = 10;
        } else {
            k = rand() % static_cast<long long>(2e9) + 1;
            t = rand() % 10 + 1;
        }

        out << k << " " << t << "\n";
    }

    return 0;
}