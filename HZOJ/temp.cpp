/************************************************************
    File Name : temp.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Created Time: 2019-11-25 23:59:01
************************************************************/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

void foo(int i) { cout << "FOO INT"; }

void foo(int *i) { cout << "FOO PTR INT"; }

int main() {
    foo(nullptr);
    return 0;
}