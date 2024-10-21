// TC 01

// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     ios::sync_with_stdio(false), cin.tie(nullptr);

//     ofstream fin("input.txt");
//     ofstream fout("output.txt");

//     int n = 100, q = 100;
//     fin << n << " " << q << "\n";
//     srand(time(0)); // use current time as seed for random generator
//     for (int i = 0; i < n; i++)
//     {
//         int num = rand() % 100 + 1; // generate random number between 1 and 100
//         fin << num << " ";
//     }
//     fin << "\n";
//     for (int i = 0; i < q; i++)
//     {
//         int a = rand() % n + 1; // generate random number between 1 and n
//         int b = rand() % n + 1; // generate random number between 1 and n
//         while (a == b)
//         {
//             b = rand() % n + 1; // ensure a and b are different
//         }
//         fin << a << " " << b << "\n";
//     }

//     // The output generation part is omitted because it requires running the provided solution which is not possible here.

//     fin.close();
//     fout.close();

//     return 0;
// }

// TC 02 

// #include <bits/stdc++.h>
// using namespace std;

// int main() {
//      srand(time(0));

//     ofstream fin("input.txt");
//     ofstream fout("output.txt");vn

//     int n = 1000, q = 100;
//     fin << n << " " << q << "\n";

//     vector<int> p(n);
//     iota(p.begin(), p.end(), 1);
//     random_device rd;
//     mt19937 g(rd());
//     shuffle(p.begin(), p.end(), g);

//     for (int i = 0; i < n; ++i) {
//         fin << p[i] << " ";
//     }
//     fin << "\n";

//     for (int i = 0; i < q; i++) {
//         int a = rand() % n + 1; // a in [1, n]
//         int b = rand() % (n - a) + a + 1; // b in [a+1, n]
//         fin << a << " " << b << "\n";
//     }

//     fin.close();
//     fout.close();

//     return 0;
// }

// TC 03

// #include <bits/stdc++.h>
// using namespace std;

// int main() {
//     srand(time(0));

//     ofstream fin("input.txt");
//     ofstream fout("output.txt");

//     int n = 100, q = 1000;
//     fin << n << " " << q << "\n";

//     vector<int> p(n);
//     iota(p.begin(), p.end(), 1);
//     random_device rd;
//     mt19937 g(rd());
//     shuffle(p.begin(), p.end(), g);

//     for (int i = 0; i < n; ++i) {
//         fin << p[i] << " ";
//     }
//     fin << "\n";

//     for (int i = 0; i < q; i++) {
//         int a = rand() % n + 1; // a in [1, n]
//         int b = rand() % (n - a + 1) + a; // b in [a, n]
//         fin << a << " " << b << "\n";
//     }

//     fin.close();
//     fout.close();

//     return 0;
// }

// TC IDK

// #include <bits/stdc++.h>
// using namespace std;

// int main() {
//     srand(time(0));

//     for (int t = 1; t <= 1; ++t) {
//         ofstream fin("input" + to_string(t) + ".txt");
//         ofstream fout("output" + to_string(t) + ".txt");

//         int n = 1000, q = 10000;
//         fin << n << " " << q << "\n";

//         vector<int> p(n);
//         iota(p.begin(), p.end(), 1);
//         random_device rd;
//         mt19937 g(rd());
//         shuffle(p.begin(), p.end(), g);

//         for (int i = 0; i < n; ++i) {
//             fin << p[i] << " ";
//         }
//         fin << "\n";

//         for (int i = 0; i < q; i++) {
//             int a = rand() % n + 1; // a in [1, n]
//             int b = rand() % (n - a + 1) + a; // b in [a, n]
//             fin << a << " " << b << "\n";
//         }

//         fin.close();
//         fout.close();
//     }

//     return 0;
// }

// TC 11-15

// #include <bits/stdc++.h>
// using namespace std;

// int main() {
//     srand(time(0));

//     for (int t = 1; t <= 5; ++t) {
//         ofstream fin("input" + to_string(t) + ".txt");
//         ofstream fout("output" + to_string(t) + ".txt");

//         int n = 100000 * t, q = 50000 * t;
//         fin << n << " " << q << "\n";

//         vector<int> p(n);
//         iota(p.begin(), p.end(), 1);
//         random_device rd;
//         mt19937 g(rd());
//         shuffle(p.begin(), p.end(), g);

//         for (int i = 0; i < n; ++i) {
//             fin << p[i] << " ";
//         }
//         fin << "\n";

//         for (int i = 0; i < q; i++) {
//             int a = rand() % n + 1; // a in [1, n]
//             int b = rand() % (n - a + 1) + a; // b in [a, n]
//             fin << a << " " << b << "\n";
//         }

//         fin.close();
//         fout.close();
//     }

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;

// int main() {
//     srand(time(0));

//     for (int t = 12; t <= 30; ++t) {
//         ofstream fin("input" + to_string(t) + ".txt");
//         ofstream fout("output" + to_string(t) + ".txt");

//         int n = rand() % 100000 + 1; // n in [1, 100000]
//         int q = rand() % 50000 + 1; // q in [1, 50000]
//         fin << n << " " << q << "\n";

//         vector<int> p(n);
//         iota(p.begin(), p.end(), 1);
//         random_device rd;
//         mt19937 g(rd());
//         shuffle(p.begin(), p.end(), g);

//         for (int i = 0; i < n; ++i) {
//             fin << p[i] << " ";
//         }
//         fin << "\n";

//         for (int i = 0; i < q; i++) {
//             int a = rand() % n + 1; // a in [1, n]
//             int b = rand() % (n - a + 1) + a; // b in [a, n]
//             fin << a << " " << b << "\n";
//         }

//         fin.close();
//         fout.close();
//     }

//     return 0;
// }


#include <bits/stdc++.h>
using namespace std;

int main() {
    srand(time(0));

    for (int t = 30; t <= 31; ++t) {
        ofstream fin("input" + to_string(t) + ".txt");
        ofstream fout("output" + to_string(t) + ".txt");

        int n = 300000; // n in [1, 100000]
        int q = 30000; // q in [1, 50000]
        fin << n << " " << q << "\n";

        vector<int> p(n);
        iota(p.begin(), p.end(), 1);
        random_device rd;
        mt19937 g(rd());
        shuffle(p.begin(), p.end(), g);

        for (int i = 0; i < n; ++i) {
            fin << p[i] << " ";
        }
        fin << "\n";

        for (int i = 0; i < q; i++) {
            int a = rand() % n + 1; // a in [1, n]
            int b = rand() % (n - a + 1) + a; // b in [a, n]
            fin << a << " " << b << "\n";
        }

        fin.close();
        fout.close();
    }

    return 0;
}