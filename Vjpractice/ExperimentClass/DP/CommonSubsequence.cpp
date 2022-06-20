/*A subsequence of a given sequence is the given sequence with some elements (possible none) left out. Given a sequence X = < x1, x2, ..., xm > another sequence Z = < z1, z2, ..., zk > is a subsequence of X if there exists a strictly increasing sequence < i1, i2, ..., ik > of indices of X such that for all j = 1,2,...,k, xij = zj. For example, Z = < a, b, f, c > is a subsequence of X = < a, b, c, f, b, c > with index sequence < 1, 2, 4, 6 >. Given two sequences X and Y the problem is to find the length of the maximum-length common subsequence of X and Y.
Input
The program input is from the std input. Each data set in the input contains two strings representing the given sequences. The sequences are separated by any number of white spaces. The input data are correct.
Output
For each set of data the program prints on the standard output the length of the maximum-length common subsequence from the beginning of a separate line.
Sample Input
abcfbc         abfcab
programming    contest 
abcd           mnp
Sample Output
4
2
0
*/
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
char str1[1000];
char str2[1000];
int maxLen[1000][1000];

int main() {
    while (cin >> str1 >> str2) {
        int length1 = strlen(str1);
        int length2 = strlen(str2);
        for (int i = 0; i <= length1; i++)
            maxLen[i][0] = 0;
        for (int j = 0; j <= length2; j++)
            maxLen[0][j] = 0;
            for (int i = 1; i <= length1; i++) {
                for (int j = 1; j <= length2; j++) {
                    if (str1[i - 1] == str2[j - 1])
                        maxLen[i][j] = maxLen[i - 1][j - 1] + 1;
                    else
                        maxLen[i][j] = max(maxLen[i][j - 1], maxLen[i - 1][j]);
                }
            }
        cout << maxLen[length1][length2] << endl;
    }
    return 0;
}