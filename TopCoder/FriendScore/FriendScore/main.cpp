//
//  main.cpp
//  FriendScore
//
//  Created by 이운형 on 14/05/2019.
//  Copyright © 2019 201302458. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
 friends : 1~50개의 요소를 갖는 배열
 각 요소는 반드시 배열의 크기 N만큼 'Y' 또는 'N'이 있다.
 모든 i,j에대해 friends[i][j] == friends[j][i]
 모든 i에 대해 friends[i][i]는 'N'입니다.
 */

class FriendScore {
public:
    int highestScore(vector <string> friends) {
        int ans = -1;
        
        for (int i = 0; i < friends.size(); i++) {
            int cnt = 0;
            
            for (int k = 0; k < friends[i].size(); k++) {
                if (i == k) continue;
                
                if (friends[i][k] == 'Y') {
                    cnt++;
                } else {
                    for (int j = 0; j < friends.size(); j++) {
                        if (i == j) continue;
                        if (friends[j][i] == 'Y' && friends[j][k] == 'Y') cnt++;
                    }
                }
            }
            
            ans = max(ans, cnt);
        }
        return ans;
    }
};

int main() {
    FriendScore f = FriendScore();
    
    vector<string> friends = { "NYNNN", "YNYNN", "NYNYN", "NNYNY", "NNNYN"};
    cout << f.highestScore(friends) << '\n';
}
