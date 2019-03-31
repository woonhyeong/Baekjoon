//
//  main.cpp
//  1561
//
//  Created by 이운형 on 29/03/2019.
//  Copyright © 2019 201302458. All rights reserved.
//

#include <stdio.h>

int t[10001];

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    
    for (int i = 0; i < m; i++) {
        scanf("%d", &t[i]);
    }
    
    if (n <= m) {
        printf("%d\n",n);
        return 0;
    }
    
    long long min = 0;
    long long max = 2000000000LL*300000LL;
    
    while (min <= max) {
        long long mid = (min+max)/2;
        long long end = m;
        for (int i = 0; i < m; i++) {
            end += mid/t[i];
        }
        
        long long begin = end + 1;
        for (int i = 0; i < m; i++) {
            if (mid % t[i] == 0) begin -= 1;
        }
        
        if (n < begin) {
            max = mid-1;
        } else if (n > end) {
            min = mid+1;
        } else {
            for (int i = 0; i < m; i++) {
                if (mid%t[i] == 0) {
                    if (n == begin) {
                        printf("%d\n",i+1);
                        return 0;
                    }
                    begin += 1;
                }
            }
        }
    }
}
