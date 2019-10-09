//
//  main.cpp
//  2098
//
//  Created by 이운형 on 2019/10/09.
//  Copyright © 2019 201302458. All rights reserved.
//

#include <stdio.h>
#include <limits.h>

int map[16][16];
bool check[16];
int n;
int min_sum = INT_MAX;

void dfs(int s, int sum, int cnt) {
    if (cnt == n && map[s][0] != 0) {
        sum += map[s][0];
        if (min_sum > sum) {
            min_sum = sum;
        }
        return;
    }
    
    for (int i = 1; i < n; i++) {
        if (check[i] || map[s][i] == 0) continue;
        
        check[i] = true;
        dfs(i, sum+map[s][i], cnt+1);
        check[i] = false;
    }
}

void solve() {
    int s = 0;
    
    for (int i = 1; i < n; i++) {
        check[i] = true;
        dfs(i, map[s][i], 2);
        check[i] = false;
    }
    
    printf("%d\n", min_sum);
}

void input() {
    scanf("%d",&n);
    for (int i = 0; i < n; i++) {
        for (int k = 0; k < n; k++) {
            scanf("%d",&map[i][k]);
        }
    }
}

int main(int argc, const char * argv[]) {
    input();
    solve();
    return 0;
}
