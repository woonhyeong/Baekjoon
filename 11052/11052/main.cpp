//
//  main.cpp
//  11052
//
//  Created by 이운형 on 2019/10/16.
//  Copyright © 2019 201302458. All rights reserved.
//

#include <stdio.h>

int money[1001];
int p[1001];
int main(int argc, const char * argv[]) {
    int n;
    scanf("%d", &n);
    
    for (int i = 1; i <= n; i++) {
        scanf("%d", &p[i]);
    }
    
    for (int i = 1; i <= n; i++) {
        for (int k = 1; k <= i; k++) {
            money[i] = money[i] < money[i-k]+p[k] ? money[i-k]+p[k]:money[i];
        }
    }
    
    printf("%d\n", money[n]);
    return 0;
}
