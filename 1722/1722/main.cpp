//
//  main.cpp
//  1722
//
//  Created by 이운형 on 01/04/2019.
//  Copyright © 2019 201302458. All rights reserved.
//

#include <stdio.h>

int a[21];
bool c[21];

long long fecto(int num) {
    long long r = 1;
    for (int i = 1; i <=num; i++) {
        r *= i;
    }
    return r;
}

int main() {
    int n, mod;
    scanf("%d",&n);
    
    for (int i = 0, j = 1; i < n; i++,j++) {
        a[i] = j;
    }
    scanf("%d",&mod);
    
    if (mod == 1) {
        long long d;
        int b[n];
        scanf("%lld",&d);
        
        for (int i = 0; i<n; i++) {
            for (int k = 1; k <= n; k++) {
                if (c[k] == true) continue;
                if (d > fecto(n-i-1)) {
                    d -= fecto(n-i-1);
                } else {
                    b[i] = k;
                    c[k] = true;
                    break;
                }
            }
        }
        
        for (int i = 0; i<n; i++) {
            printf("%d ",b[i]);
        }
        printf("\n");
    } else if (mod == 2) {
        int b[n];
        long long r = 0;
        for (int i = 0; i<n; i++) {
            scanf("%d",&b[i]);
        }
        
        for (int i = 0; i<n; i++) {
            for (int k = 1; k<b[i]; k++) {
                if (!c[k]) {
                    r += fecto(n-(i+1));
                }
            }
            c[b[i]] = true;
        }
        printf("%lld\n",r+1);
    }
}
