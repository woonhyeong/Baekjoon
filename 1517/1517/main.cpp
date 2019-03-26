//
//  main.cpp
//  1517
//
//  Created by 이운형 on 26/03/2019.
//  Copyright © 2019 201302458. All rights reserved.
//

#include <stdio.h>

int A[500000];
long long r = 0;

void merge(int s, int e, int m) {
    int i  = s;
    int j = m+1;
    int k = 0;
    int b[e-s+1];
    
    while (i <= m && j <= e) {
        if (A[i] <= A[j]) {
            b[k++] = A[i++];
        } else {
            b[k++] = A[j++];
            r += (m-i+1);
        }
    }
    
    while (i <= m) b[k++] = A[i++];
    while (j <= e) b[k++] = A[j++];
    for (int i = s; i <= e; i++) A[i] = b[i-s];
}

void divide(int s, int e) {
    if (s == e) return;
    
    int mid = (s+e)/2;
    divide(s, mid);
    divide(mid+1, e);
    merge(s, e, mid);
}

int main() {
    int n;
    scanf("%d",&n);
    
    for (int i = 0; i < n; i++) {
        scanf("%d",&A[i]);
    }
    divide(0, n-1);
    printf("%lld\n",r);
}
