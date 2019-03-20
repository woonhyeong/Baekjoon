//
//  main.cpp
//  1783
//
//  Created by 이운형 on 20/03/2019.
//  Copyright © 2019 201302458. All rights reserved.
//
/*
    나이트는 상.하로 움직일 때, 가로로 가장 많은 칸을 움직 일 수 있다.
    그래서 높이가 3이상 일 때는 상,하로 움직이고
    높이가 2일 때는 가로로 2칸씩 이동할 수 밖에 없다.
    높이가 2일 때 4칸이상 움직일 수 없으므로 최대값은 4이다.
 */

#include <stdio.h>

int main() {
    int n, m, r = 0;
    scanf("%d %d", &n, &m);
    
    if (n == 1) {
        r = 1;
    } else if (n == 2) {
        if (m < 3) {
            r = 1;
        } else {
            r = (m+1)/2 < 4 ? (m+1)/2 : 4;
        }
    } else {
        if (m < 7) {
            r = m < 4 ? m : 4;
        } else {
            r = m-2;
        }
    }
    
    printf("%d\n",r);
    return 0;
}


/*
 #include <stdio.h>
 
 int main() {
 int n, m;
 scanf("%d %d", &n, &m);
 
 if (n == 1) {
 printf("1");
 } else if (n == 2) {
 printf("%d", m<7?(m+1)/2:4);
 } else {
 printf("%d", m - (m>4) - (m>5));
 }
 return 0;
 }
 */
