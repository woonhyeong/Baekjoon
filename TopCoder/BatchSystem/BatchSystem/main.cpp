//
//  main.cpp
//  BatchSystem
//
//  Created by 이운형 on 10/06/2019.
//  Copyright © 2019 201302458. All rights reserved.
//

/*
 1. dictionary로 각 user의 duration 합을 구함
 2. dictionary를 오름차순 정렬
 3. 사전순으로 정답을 구함
 */

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
using namespace std;

bool cmp(const pair<string, long long> &A, const pair<string, long long> &B) {
    if (A.second != B.second) {
        return A.second < B.second;
    } else {
        if (A.first.compare(B.first) < 0) {
            return true;
        } else return false;
    }
}

class BatchSystem {
public:
    vector<int> schedule(vector<int> duration, vector<string> user) {
        map<string,long long> dic;
        vector<pair<string, long long>> pairs;
        vector<int> ans;

        for (int i = 0; i < duration.size(); i++) {
            dic[user[i]] += duration[i];
        }
        
        /* map을 value로 정렬하기 위해 paris에 dic의 값을 복사 */
        for (auto iter = dic.begin(); iter != dic.end(); ++iter) {
            pairs.push_back(*iter);
        }
        /* user의 duration에 따른 오름차순 정렬 */
        sort(pairs.begin(), pairs.end(), cmp);

        for (int i = 0; i < pairs.size(); i++) {
            string current = pairs[i].first;

            for (int k = 0; k < user.size(); k++) {
                if (user[k].compare(current) == 0) {
                    ans.push_back(k);
                }
            }
        }

        return ans;
    }
};

int main() {
    vector<int> duration = {400,100,100,200};
    vector<string> user = {"Danny Messer", "Stella Bonasera", "Stella Bonasera", "Mac Taylor"};
    BatchSystem b = BatchSystem();
    vector<int> ans = b.schedule(duration, user);
    
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << endl;
    }
    
    return 0;
}
