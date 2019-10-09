//
//  main.cpp
//  1978
//
//  Created by 이운형 on 2019/10/09.
//  Copyright © 2019 201302458. All rights reserved.
//

#include <stdio.h>

bool check[1001];

void era() {
    for (int i = 2; i*i <= 1000; i++) {
        if (!check[i]) {
            for (int j = i*i; j<=1000; j+=i) {
                check[j] = true;
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    era();
    check[1] = true;
    
    int n, i, cnt = 0;
    scanf("%d",&n);

    while (n--) {
        scanf("%d",&i);
        if (!check[i]) cnt++;
    }
    
    printf("%d\n",cnt);
    
    return 0;
}
