//
//  main.swift
//  1006
//
//  Created by 이운형 on 27/01/2019.
//  Copyright © 2019 201302458. All rights reserved.
//

let testCount = Int(readLine()!)!
var map : Int = 0
var platoon : Int = 0
var enemy = [Int]()
var dp = [[[Int]]]()

func cirIndex(_ index:Int)->Int {
    if index < 0 {
        return (map-1)
    } else {
        return index
    }
}

func cover(_ index:Int, _ prev:Int, _ last: Int) -> Int {
    if dp[index][prev][last] >= 0 {
        return dp[index][prev][last]
    }
    
    let bottom : Bool = (enemy[index] + enemy[index == 0 ? map-1 : index-1] <= platoon)
    let top : Bool = (enemy[index+map] + enemy[index+map-1] <= platoon)
    let topAndBottom : Bool = (enemy[index] + enemy[index+map] <= platoon)
    
    if index == map - 1 {
        if index == 0 {
            return topAndBottom ? 1 : 2
        }
        dp[index][prev][last] = 2
        
        if last == 0 {
            if bottom && (prev != 1) && (prev != 3) { dp[index][prev][last] = 1 }
            if top && (prev < 2) { dp[index][prev][last] = 1 }
            if topAndBottom { dp[index][prev][last] = 1 }
            if top && bottom && prev == 0 { dp[index][prev][last] = 0 }
        } else if last == 1 {
            if top && prev < 2 { dp[index][prev][last] = 1 }
        } else if last == 2 {
            if bottom && prev != 1 && prev != 3 { dp[index][prev][last] = 1 }
        }
        
        return dp[index][prev][last]
    }
    
    dp[index][prev][last] = 2 + cover(index + 1, 0, last)
    
    if bottom && prev != 1 && prev != 3 { dp[index][prev][last] = min(dp[index][prev][last], 1 + cover(index+1, 1, index == 0 ? 1 : last))}
    if top && prev < 2 { dp[index][prev][last] = min(dp[index][prev][last], 1 + cover(index+1, 2, index == 0 ? 2: last))}
    if top && bottom && prev == 0 { dp[index][prev][last] = min(dp[index][prev][last], cover(index+1, 3, index == 0 ? 3 : last))}
    if topAndBottom { dp[index][prev][last]  = min(dp[index][prev][last], 1 + cover(index+1, 3, last) )}
    
    return dp[index][prev][last]
}

for _ in 1...testCount {
    let platoonInput = readLine()!.split(separator: " ").map{Int($0)!}
    map = platoonInput[0]
    platoon = platoonInput[1]
    
    for _ in 0...1 {
        let enemyInput = readLine()!.split(separator: " ").map{Int($0)!}
        for i in 0...(map-1) {
            enemy.append(enemyInput[i])
        }
    }
    dp = [[[Int]]](repeating: Array(repeating: Array(repeating: -1, count: 4), count: 4), count: map)
    
    print(cover(0,0,0))
}
