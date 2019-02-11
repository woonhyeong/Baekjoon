//
//  main.swift
//  1015
//
//  Created by 이운형 on 11/02/2019.
//  Copyright © 2019 201302458. All rights reserved.
//
//  A의 값에 따라 정렬 후에 정렬된 A의 index를 이용하여 P[index]의 값을 구하는 문제이다.
//  아래 코드는 명확하게 A의 값과 index를 구조체로 만들어 구분 하였다.
//  처음에는 틀렸는데, 이유가 value에 띠라 정렬했지만, 같을 경우 사전순으로 정렬하지 않았기 때문이였다.

struct Pair: Comparable {
    static func < (lhs: Pair, rhs: Pair) -> Bool {
        if lhs.value < rhs.value {
            return true
        } else if lhs.value == rhs.value {
            if lhs.index < rhs.index {
                return true
            } else { return false }
        } else {
            return false
        }
    }
    let value : Int
    let index : Int
}

let length = Int(readLine()!)!
var a = [Pair]()
var p: [Int] = Array(repeating: 0, count: length)

let element = readLine()!.split(separator: " ").map{Int($0)!}
for i in 0..<length {
    a.append(Pair(value: element[i], index: i))
}

a = a.sorted{$0 < $1}

for i in 0..<length {
    p[a[i].index] = i
}

for i in 0..<length {
    print(p[i], separator: "", terminator: " ")
}

/*
    다른 분의 풀이를 이용한 방식
 */

//let length = Int(readLine()!)!
//var p = [Int]()
//var b = [Int]()
//var output = ""
//let a = readLine()!.split(separator: " ").map{Int($0)!}
//
//for i in 0..<length {
//    p.append(i)
//    b.append(i)
//}
//p.sort{a[$0] == a[$1] ? $0 < $1 : a[$0] < a[$1]}
//b.sort{p[$0] < p[$1]}
//
//for i in b {
//    output += "\(i) "
//}
//
//print(output)

