//
//  main.cpp
//  10974
//
//  Created by 이운형 on 01/04/2019.
//  Copyright © 2019 201302458. All rights reserved.
//

#include <stdio.h>
int a[8];
int n;
bool next_permutation(){
    int i = n-1;
    while (i > 0 && a[i-1] >= a[i]) i-=1;
    
    if (i <= 0) return false;
    
    int j = n-1;
    while (a[i-1] >= a[j]) j-=1;
    int temp = a[i-1];
    a[i-1] = a[j];
    a[j] = temp;
    
    j = n-1;
    while (i < j) {
        temp = a[i];
        a[i] = a[j];
        a[j] = temp;
        i+=1; j-=1;
    }
    return true;
}

int main() {
    scanf("%d",&n);

    for (int i = 0, j = 1; i < n; i++, j++) {
        a[i] = j;
    }
    
    for (int i = 0; i < n; i++) {
        printf("%d ",a[i]);
    }
    printf("\n");
    while (next_permutation()) {
        for (int i = 0; i < n; i++) {
            printf("%d ",a[i]);
        }
        printf("\n");
    }
}
