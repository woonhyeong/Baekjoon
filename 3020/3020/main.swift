//
//  main.swift
//  3020
//
//  Created by 이운형 on 13/03/2019.
//  Copyright © 2019 201302458. All rights reserved.
//

let input = readLine()!.split(separator: " ").map{Int($0)!}
let (n,h) = (input[0], input[1])

var top: [Int] = Array(repeating: 0, count: h)
var bottom: [Int] = Array(repeating: 0, count: h)
var up: [Int] = Array(repeating: 0, count: h + 1)
var down: [Int] = Array(repeating: 0, count: h + 1)

for _ in 1...n/2 {
    let index1 = Int(readLine()!)!
    let index2 = Int(readLine()!)!
    bottom[index1-1] += 1
    top[index2-1] += 1
}

for i in stride(from: h-1, through: 0, by: -1) {
    up[i] = top[i] + up[i+1]
    down[i] = bottom[i] + down[i+1]
}

var result = 0
var min = Int.max

for k in 0..<h {
    let sum = up[k] + down[h - k - 1]
    
    if sum == min {
        result += 1
    } else if sum < min {
        min = sum
        result = 1
    }
}

print("\(min) \(result)")
