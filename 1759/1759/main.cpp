//
//  main.cpp
//  1759
//
//  Created by 이운형 on 2019/10/09.
//  Copyright © 2019 201302458. All rights reserved.
//

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

char hint[15];
int n, hn;

void input() {
    cin >> n >> hn;
    for (int i = 0; i < hn; i++) {
        cin >> hint[i];
    }
}

bool check(string pwd) {
    int mo = 0, ja = 0;
    for (int i = 0; i < n; i++) {
        char c = pwd[i];
        
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            mo++;
        } else {
            ja++;
        }
    }
    
    if (mo >= 1 && ja >= 2) return true;
    return false;
}
void brute(string pwd, int cnt, int index) {
    if (cnt == n && check(pwd)) {
        cout << pwd << '\n';
        return;
    }
    
    if (index >= hn) return;
    
    brute(pwd+hint[index], cnt+1, index+1);
    brute(pwd, cnt, index+1);
}

void solve() {
    sort(hint, hint+hn);
    string pwd = "";
    
    brute(pwd+hint[0], 1, 1);
    brute(pwd, 0, 1);
}

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    input();
    solve();
    
    return 0;
}
