
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
29
30
31
32
33
34
35
36
37
38
#include <algorithm>
#include <string>
#include <vector>
#include <map>

using namespace std;
map<string,int> combi;

void combination(string src, string crs, int depth) {
    if (crs.size() == depth) combi[crs]++;

    else for (int i = 0; i < src.size(); i++)
        combination(src.substr(i+1), crs+src[i], depth);
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;

    for (string &order : orders)
        sort(order.begin(), order.end());

    for (int crs : course) {
        for (string order : orders)
            combination(order, "", crs);

        int sup = 0;
        for (auto it : combi)
            sup = max(sup, it.second);
        for (auto it : combi)
            if (sup >= 2 && it.second == sup)
                answer.push_back(it.first);
        combi.clear();
    }

    sort(answer.begin(), answer.end());
    return answer;
}