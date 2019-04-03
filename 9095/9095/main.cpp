//
//  main.cpp
//  9095
//
//  Created by 이운형 on 02/04/2019.
//  Copyright © 2019 201302458. All rights reserved.
//

#include <iostream>

int main() {
    int n,d,r=0;
    scanf("%d",&n);
    
    while (n--) {
        scanf("%d",&d);
        r = 0;
        for (int l1 = 1; l1 <= 3; l1++) {
            if (l1 == d) r+=1;
            for (int l2 = 1; l2 <= 3; l2++) {
                if (l1+l2 == d) r+=1;
                for (int l3 = 1; l3 <= 3; l3++) {
                    if (l1+l2+l3 == d) r+=1;
                    for (int l4 = 1; l4 <= 3; l4++) {
                        if (l1+l2+l3+l4 == d) r+=1;
                        for (int l5 = 1; l5 <= 3; l5++) {
                            if (l1+l2+l3+l4+l5 == d) r+=1;
                            for (int l6 = 1; l6 <= 3; l6++) {
                                if (l1+l2+l3+l4+l5+l6 == d) r+=1;
                                for (int l7 = 1; l7 <= 3; l7++) {
                                    if (l1+l2+l3+l4+l5+l6+l7 == d) r+=1;
                                    for (int l8 = 1; l8 <= 3; l8++) {
                                        if (l1+l2+l3+l4+l5+l6+l7+l8 == d) r+=1;
                                        for (int l9 = 1; l9 <= 3; l9++) {
                                            if (l1+l2+l3+l4+l5+l6+l7+l8+l9 == d) r+=1;
                                            for (int l10 = 1; l10 <= 3; l10++) {
                                                if (l1+l2+l3+l4+l5+l6+l7+l8+l9+l10 == d) r+=1;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        printf("%d\n",r);
    }
}
