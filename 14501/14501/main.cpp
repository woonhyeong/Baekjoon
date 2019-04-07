//
//  main.cpp
//  14501
//
//  Created by 이운형 on 07/04/2019.
//  Copyright © 2019 201302458. All rights reserved.
//

#include <iostream>
using namespace std;

int a[15][15];
int n;

int dfs(int idx) {
    if (idx >=n) return 0;
    
    int day = a[idx][0];
    int val = a[idx][1];
    
    int c1,c2;
    if (day > n-idx) {
        c1 = 0;
    } else {
        c1 = val + dfs(idx+day);
    }
    c2 = dfs(idx+1);
    return max(c1, c2);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    
    for (int i = 0; i<n; i++) {
        cin >> a[i][0] >> a[i][1];
    }
    
    printf("%d\n",dfs(0));
}
