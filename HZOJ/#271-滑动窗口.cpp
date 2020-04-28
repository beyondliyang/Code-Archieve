/************************************************************
    File Name : #271-滑动窗口.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/04/28 20:02:25
************************************************************/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define MAX_N 300000

int a[MAX_N + 5];
int q[MAX_N + 5], head = 0, tail = 0;

int main() {
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) {
        while (tail - head && a[q[tail - 1]] >= a[i]) tail--;
        q[tail++] = i;
        if (q[head] <= i - k) head++;
        if (i < k) continue;
        i == k || cout << " ";
        cout << a[q[head]];
    }
    cout << endl;
    head = tail = 0;
    for (int i = 1; i <= n; ++i) {
        while (tail - head && a[q[tail - 1]] <= a[i]) tail--;
        q[tail++] = i;
        if (q[head] <= i - k) head++;
        if (i < k) continue;
        i == k || cout << " ";
        cout << a[q[head]];
    }
    cout << endl;
    return 0;
}