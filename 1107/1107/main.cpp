//
//  main.cpp
//  1107
//
//  Created by 이운형 on 02/04/2019.
//  Copyright © 2019 201302458. All rights reserved.
//

#include <stdio.h>

bool broken[10];
int possible(int n) {
    int len = 0;
    if (n == 0) {
        len = broken[0]? 0 : 1;
        return len;
    }
    
    while (n > 0) {
        if (broken[n%10]) {
            return 0;
        }
        len+=1;
        n/=10;
    }
    return len;
}

int main() {
    int n, m, input;
    scanf("%d",&n);
    scanf("%d",&m);
    
    for (int i = 0; i< m; i++) {
        scanf("%d",&input);
        broken[input] = true;
    }
    
    int ans = n - 100;
    if (ans < 0) ans = -ans;
    
    for (int i = 0; i<=1000000; i++) {
        int c = i;
        int len = possible(c);
        if(len > 0){
            int press = n - c;
            if (press < 0) press = -press;
            if ( ans > press + len) ans = press + len;
        }
    }
    printf("%d\n",ans);
}
