//
//  main.swift
//  1018
//
//  Created by 이운형 on 15/02/2019.
//  Copyright © 2019 201302458. All rights reserved.
//
// W = 0, B = 1
// answer 라는 정답 배열을 미리 만들어놓는다.
// answer 배열을 입력받는 map 배열과 비교하며 정답을 찾는다.
// compare 함수의 mode 파라미터는 첫 글자가 W일때와 B일때로 나눈 것이다.

let input = readLine()!.split(separator: " ").map{Int($0)!}
let (n,m) = (input[0], input[1])
var map = [[Int]]()
var answer = [[0,1,0,1,0,1,0,1],[1,0,1,0,1,0,1,0],[0,1,0,1,0,1,0,1],[1,0,1,0,1,0,1,0],[0,1,0,1,0,1,0,1],[1,0,1,0,1,0,1,0],[0,1,0,1,0,1,0,1],[1,0,1,0,1,0,1,0]]
var resultValue = Int.max

func compare(_ x:Int, _ y:Int, _ mode:Int) -> Int {
    var result = 0
    if mode == 0 {
        for i in 0..<8 {
            for k in 0..<8 {
                if map[x+i][y+k] != answer[i][k] {
                    result += 1
                }
            }
        }
    } else {
        for i in 0..<8 {
            for k in 0..<8 {
                if map[x+i][y+k] == answer[i][k] {
                    result += 1
                }
            }
        }
    }
    return result
}

for _ in 0..<n {
    let a = readLine()!
    var arr = [Int]()
    
    for c in a {
        c == "W" ? arr.append(0) : arr.append(1)
    }
    map.append(arr)
}

for i in 0...n-8 {
    for k in 0...m-8 {
        resultValue = min(resultValue, compare(i, k, 0))
        resultValue = min(resultValue, compare(i, k, 1))
    }
}

print(resultValue)
