//
//  main.cpp
//  11407
//
//  Created by 이운형 on 11/03/2019.
//  Copyright © 2019 201302458. All rights reserved.
//

/*
 그리디 알고리즘 - 동전0
 n개의 입력에서 A(n)은 A(n-1)의 배수이기 때문에 그리디 알고리즘이 적용된다.
 */
#include <iostream>
#include <vector>

using namespace std;
int main() {
    int n,k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i<n; i++) {
        cin >> arr[i];
    }
    int result = 0;
    for (int i = n-1; i >= 0; i--) {
        result += k/arr[i];
        k %= arr[i];
    }
    cout << result <<'\n';
    return 0;
}
