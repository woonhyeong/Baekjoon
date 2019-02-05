//
//  main.swift
//  1012
//
//  Created by 이운형 on 05/02/2019.
//  Copyright © 2019 201302458. All rights reserved.
//

let dx = [1, 0 , -1, 0]
let dy = [0, 1, 0 , -1]

func findSideCabbage(_ x: Int, _ y:Int, _ map:[[Int]], _ visit:inout [[Bool]], _ row:Int, _ column:Int) {
    if map[x][y] != 1 && !visit[x][y] {
        return
    } else {
        visit[x][y] = true
    }
    
    for i in 0...3 {
        let nextX = x + dx[i]
        let nextY = y + dy[i]
        if nextX >= 0 && nextY >= 0 && nextX < row && nextY < column {
            if map[nextX][nextY] == 1 && !visit[nextX][nextY] {
                findSideCabbage(nextX, nextY, map, &visit, row, column)
            }
        }
    }
}

let testCase = Int(readLine()!)!

for _ in 0 ..< testCase {
    let input = readLine()!.split(separator: " ").map{Int($0)!}
    let (m, n) = (input[0], input[1])
    var map: [[Int]] = Array(repeating: Array(repeating: 0, count: n), count: m)
    var visit: [[Bool]] = Array(repeating: Array(repeating: false, count: n), count: m)
    
    for _ in 0 ..< input[2] {
        let pointInput = readLine()!.split(separator: " ").map{Int($0)!}
        map[pointInput[0]][pointInput[1]] = 1
    }
    
    var result = 0
    for i in 0 ..< m {
        for j in 0 ..< n {
            if map[i][j] == 1 {
                if !visit[i][j] {
                    findSideCabbage(i, j, map, &visit, m, n)
                    result += 1
                } else {
                    continue
                }
                
            }
        }
    }
    
    print(result)
}
