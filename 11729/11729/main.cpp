//
//  main.cpp
//  11729
//
//  Created by 이운형 on 24/03/2019.
//  Copyright © 2019 201302458. All rights reserved.
//

#include <stdio.h>

int result = 0, k = 0;
char buff[4200000];

void move(int n, int x , int y){
    if (n == 0) {
        return;
    }
    move(n-1, x, 6-x-y);
    buff[k++] = x +'0';
    buff[k++] = ' ';
    buff[k++] = y + '0';
    buff[k++] = '\n';    result += 1;
    move(n-1, 6-x-y, y);
}

int main() {
    int n;
    scanf("%d", &n);
    
    move(n, 1, 3);
    buff[k++] = '\0';
    printf("%d\n",result);
    printf("%s",buff);
}
