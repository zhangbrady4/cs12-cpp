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

    while ((pos = x.find("\\r", pos)) != string::npos) {
        x.erase(pos, 2);
    }

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

int main()
{
    map<char, int> ocr;
    vector<pair<char, int>> srted;

    string line = "The 1988�C89 FA Cup third-round match between Sutton United and Coventry City was an association football game played at Gander Green Lane in Sutton, on 7 January 1989. Coventry City entered the FA Cup in the third round, as they participated in the Football League First Division, the top tier of English league football. Sutton United of the Conference, the fifth tier of English football, had started their cup run in the preliminary round, winning three ties to reach this stage of the competition. Coventry, the away team, went into the match as strong favourites, a reflection of the gulf in divisions that separated the two teams. The match was refereed by Alf Buksh in front of 8,000 spectators. Coventry's Brian Kilcline had the best early chance after he received the ball while unmarked in the penalty area, but his header was straight at Sutton goalkeeper Trevor Roffey. The home side took the lead three minutes before half-time when Mickey Stephens took a corner towards the near post which was missed by Coventry goalkeeper Steve Ogrizovic and then volleyed into the goal by Tony Rains. Seven minutes into the second half, Coventry were level after Steve Sedgley passed the ball into the Sutton penalty area, allowing David Phillips to shoot past an advancing Roffey to make it 1�C1. In the 59th minute, Stephens took a corner kick short to Phil Dawson who struck an outswinging cross which Hanlan volleyed in to give Sutton the lead once again. Despite numerous late chances for Coventry, the match ended 2�C1 and Sutton United progressed to the fourth round of the FA Cup.";
    line += "One of the most famous 'giant-killings' in the competition's history, the match is among the few instances when a non-League side has defeated a club from the highest tier of English football. It remained the most recent such occasion for 24 years, until Luton Town beat Norwich City in the FA Cup fourth round in 2013. The match has been described as not only the biggest shock in the history of the FA Cup but one of the biggest in any game ever. Sutton United went on to lose 8�C0 in the fourth round to Norwich City and ended the season mid-table in the Conference. Coventry City's league form declined after the cup tie as they dropped to seventh place by the conclusion of the First Division season.";
    count(line, ocr);

    // f.clear();
    // f.seekg(0,f.beg);

    srted = sortbyval(ocr);
    display(srted);

    return 0;
}
