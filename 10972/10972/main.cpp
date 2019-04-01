//
//  main.cpp
//  10972
//
//  Created by 이운형 on 01/04/2019.
//  Copyright © 2019 201302458. All rights reserved.
//

#include <stdio.h>

int main() {
    int a[10001];
    int n;
    scanf("%d",&n);
    
    for (int i = 0; i<n; i++) {
        scanf("%d",&a[i]);
    }
    
    int i = n-1;
    while (i > 0 && a[i-1] >= a[i]) i-=1;
    if (i <= 0) {
        printf("%d\n",-1);
        return 0;
    }
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
    
    for (int i = 0; i < n; i++) printf("%d ",a[i]);
    printf("\n");
    return 0;
}
