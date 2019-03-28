//
//  main.cpp
//  2110
//
//  Created by 이운형 on 28/03/2019.
//  Copyright © 2019 201302458. All rights reserved.
//

#include <stdio.h>
#include <algorithm>
using namespace std;
int h[200000];

int main() {
    int n,c;
    scanf("%d %d", &n, &c);
    
    for (int i = 0; i < n; i++) scanf("%d", &h[i]);
    sort(h, h+n);
    
    int l = 1;
    int r = h[n-1] - h[0];
    int mid, num, s;
    
    while (l <= r) {
        mid = (l+r)/2;
        num = 1;
        s = h[0];
        for (int i = 1; i < n; i++) {
            if (h[i] - s >= mid) {
                num++;
                s = h[i];
            }
        }
        
        if (num >= c) {
            l = mid+1;
        } else {
            r = mid-1;
        }
    }
    printf("%d\n", r);
}
