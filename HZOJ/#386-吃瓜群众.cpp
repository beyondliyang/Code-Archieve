/************************************************************
    File Name : #386-吃瓜群众.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/04/08 19:42:12
************************************************************/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define MAX_N 100000

struct Node {
    int amount, id;
};

bool cmp(Node a, Node b) { return a.amount < b.amount; }

int n, m;
Node melon[MAX_N + 5];

int binary_search(int goal) {
    int l = 0, r = m - 1;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (melon[mid].amount == goal) return melon[mid].id;
        if (melon[mid].amount < goal)
            l = mid + 1;
        else if (melon[mid].amount > goal)
            r = mid - 1;
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> m >> n;
    for (int i = 0; i < m; ++i) {
        cin >> melon[i].amount;
        melon[i].id = i + 1;
    }
    sort(melon, melon + m, cmp);
    for (int i = 0; i < n; ++i) {
        int temp;
        cin >> temp;
        cout << binary_search(temp) << endl;
    }
    return 0;
}