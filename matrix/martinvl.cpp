#include <iostream>

using namespace std;

const int lo = 1;
const int hi = 8;
const int size = 16;
enum coord_t {g, h, j, k, l, m, n, o, p};

inline bool is_valid(const int i)
{
    return i >= lo && i < hi;
}

inline bool verify(const int x[])
{
    return is_valid(x[h] + x[l] - x[m])
            && is_valid(x[g] + x[k] - x[n])
            && is_valid(-x[g] - x[k] + x[m] + x[n] + x[p])
            && is_valid(-x[h] - x[l] + x[m] + x[n] + x[o])
            && is_valid(-x[h] + x[j] + x[k])
            && is_valid(-x[g] - x[j] - x[k] + x[m] + x[n] + x[o] + x[p])
            && is_valid(-x[j] - x[k] - x[l] + x[m] + x[n] + x[o] + x[p]);
}

int gen(int x[], const int pos)
{
    if (pos < 16 - (hi - lo)) {
        int sum = 0;

        for (int i = lo; i < hi; ++i) {
            x[pos] = i;
            sum += gen(x, pos+1);
        }

        return sum;
    } else {
        return verify(x);
    }
}

int main(int argc, char *argv[])
{
    int x[16 - (hi - lo)];
    cout << gen(x, 0) << endl;

    return 0;
}
