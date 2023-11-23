#include <iostream>
#include <string>
#include <vector>
using namespace std;

void computeLPSArray(string pat, int M, int* lps);

int KMPSearch(string pat, string txt)
{
    vector<int> ans;
    int M = pat.size();
    int N = txt.size();

    int lps[M];

    computeLPSArray(pat, M, lps);

    int i = 0;
    int j = 0;
    while ((N - i) >= (M - j)) {
        if (pat[j] == txt[i]) {
            j++;
            i++;
        }

        if (j == M) {
            ans.push_back(i - j + 1);
            return abs(i - 2 * M);
            j = lps[j - 1];
        }


        else if (i < N && pat[j] != txt[i]) {

            if (j != 0)
                j = lps[j - 1];
            else
                i = i + 1;
        }
    }
    return -1;
}

void computeLPSArray(string pat, int M, int* lps)
{

    int len = 0;

    lps[0] = 0;

    int i = 1;
    while (i < M) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len != 0) {
                len = lps[len - 1];

            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}

int main() {
    string a;
    cin >> a;
    string b;
    cin >> b;
    string text = a;
    text += a;

    cout << KMPSearch(b, text);

}
