#include <algorithm>
#include <cstring>
#include <fstream>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

void count(string x, map<char, int>& y)
{
    size_t pos(0);
    while ((pos = x.find("\\n", pos)) != string::npos) {
        x.erase(pos, 2);
    }
    pos = 0;

    for (auto a : x) {
        if (isalpha(a) || a == ' ') {
            a = tolower(a);
            map<char, int>::iterator p;
            if ((p = y.find(a)) != y.end()) {
                p->second++;
            } else {
                y[a] = 1;
            }
        }
    }
}

void display(vector<pair<char, int>>& y)
{
    for (auto x : y) {
        cout << x.first << " " << x.second << endl;
    }
}

bool mysort(pair<char, int> x, pair<char, int> y)
{
    return (x.second > y.second);
}

vector<pair<char, int>> sortbyval(map<char, int> z)
{
    vector<pair<char, int>> v;
    map<char, int> mapval;

    map<char, int>::iterator it;
    for (it = z.begin(); it != z.end(); it++) {
        v.push_back(make_pair(it->first, it->second));
    }

    sort(v.begin(), v.end(), mysort);

    return v;
}

int main(int argc, char* argv[])
{
    ifstream f(argv[1]);
    map<char, int> ocr;
    vector<pair<char, int>> srted;

    string line;
    while (getline(f, line)) {
        count(line, ocr);
    }
    f.clear();
    f.seekg(0, f.beg);

    srted = sortbyval(ocr);
    display(srted);

    return 0;
}
