//
//  main.cpp
//  14889
//
//  Created by 이운형 on 08/04/2019.
//  Copyright © 2019 201302458. All rights reserved.
//

#include <iostream>
#include <limits.h>
using namespace std;

int map[20][20];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int k = 0 ; k < n; k++) {
            cin >> map[i][k];
        }
    }
    
    int ans = INT_MAX;
    int max_len = 1<<n;
    
    for (int i = 1; i < max_len; i++) {
        int cnt = 0;
        for (int k = 0; k < n; k++) {
            if (i & (1<<k)) {
                cnt++;
            }
        }
        
        if (cnt != n/2) continue;
        
        int start = 0, link = 0;
        for (int j = 0; j < n; j++) {
            for (int b = j+1; b < n; b++) {
                if ( (i & (1<<j)) && (i & (1<<b)) ) {
                    start += map[j][b] + map[b][j];
                }
                if ( !(i & (1<<j)) && !(i & (1<<b)) ) {
                    link += map[j][b] + map[b][j];
                }
            }
        }
        int r = start-link>0?start-link:link-start;
        if (ans>r) ans = r;
    }
    printf("%d\n",ans);
}
