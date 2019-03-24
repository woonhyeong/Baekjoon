//
//  main.cpp
//  11728
//
//  Created by 이운형 on 24/03/2019.
//  Copyright © 2019 201302458. All rights reserved.
//

#include <stdio.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    
    int A[1000000] , B[1000000];
    
    for (int i = 0; i < n; i++) scanf("%d", &A[i]);
    for (int i = 0; i < m; i++) scanf("%d", &B[i]);
    
    int l = 0, r = 0;
    
    while (l < n && r < m) {
        if (A[l] < B[r]) {
            printf("%d ",A[l++]);
        } else {
            printf("%d ",B[r++]);
        }
    }
    
    while (l < n) printf("%d ",A[l++]);
    while (r < m) printf("%d ",B[r++]);
}
