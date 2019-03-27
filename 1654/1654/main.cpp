//
//  main.cpp
//  1654
//
//  Created by 이운형 on 26/03/2019.
//  Copyright © 2019 201302458. All rights reserved.
//

#include <stdio.h>
long long  l[10000];

int main() {
    int k, n;
    scanf("%d %d", &k, &n);
    
    long long  min = 1;
    long long max = 0;
    for (int i = 0; i < k; i++) {
        scanf("%lld", &l[i]);
        if (l[i] > max) max = l[i];
    }
    
    int r = 0;
    while (min <= max) {
        long long mid = (max + min)/2;
        for (int i = 0; i < k; i++) {
            r += l[i]/mid;
        }
        
        if (r < n) {
            max = mid-1;
        } else {
            min = mid+1;
        }
        r = 0;
    }
    printf("%lld\n", min-1);
}
