//
//  main.cpp
//  2263
//
//  Created by 이운형 on 25/03/2019.
//  Copyright © 2019 201302458. All rights reserved.
//
#include <stdio.h>

int io[100000];
int po[100000];
int position[100001];

void divide(int is, int ie, int ps, int pe) {
    if (is > ie || ps > pe) return;
    printf("%d ", po[pe]);
    int ri = position[po[pe]];
    
    divide(is, ri-1, ps, ps + ri - is -1);
    divide(ri + 1, ie, ps + ri - is, pe - 1);
}

int main() {
    int n;
    scanf("%d",&n);
    
    for (int i = 0; i<n; i++) {
        scanf("%d",&io[i]);
        position[io[i]] = i;
    }
    for (int i = 0; i<n; i++) scanf("%d",&po[i]);
    
    divide(0,n-1,0,n-1);
}
