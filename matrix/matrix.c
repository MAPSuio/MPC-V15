#include <stdio.h>

int main(int argc, char *argv[])
{
    int num = 0;
    int lo = 1;
    int hi = 8;

    for (int g = lo; g < hi; ++g) {
        for (int h = lo; h < hi; ++h) {
            for (int j = lo; j < hi; ++j) {
                for (int k = lo; k < hi; ++k) {
                    for (int l = lo; l < hi; ++l) {
                        for (int m = lo; m < hi; ++m) {
                            for (int n = lo; n < hi; ++n) {
                                for (int o = lo; o < hi; ++o) {
                                    for (int p = lo; p < hi; ++p) {
                                        int a = h + l - m;
                                        if (a < lo || a >= hi)
                                            continue;

                                        int b = g + k - n;
                                        if (b < lo || b >= hi)
                                            continue;

                                        int c = -g - k + m + n + p;
                                        if (c < lo || c >= hi)
                                            continue;

                                        int d = -h - l + m + n + o;
                                        if (d < lo || d >= hi)
                                            continue;

                                        int e = -h + j + k;
                                        if (e < lo || e >= hi)
                                            continue;

                                        int f = -g - j - k + m + n + o + p;
                                        if (f < lo || f >= hi)
                                            continue;

                                        int i = -j - k - l + m + n + o + p;
                                        if (i < lo || i >= hi)
                                            continue;

                                        ++num;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    printf("%d\n", num);
}
