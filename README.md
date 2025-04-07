# 🚗 Minimize Max Distance to Gas Station

This C++ project solves the **"Minimize Maximum Distance to Gas Station"** problem using a **binary search** approach with precision up to `1e-6`. It efficiently determines the **smallest possible maximum distance** between adjacent gas stations after adding `k` new ones optimally.

---

## 🧠 Problem Description

You are given:

- A sorted array `stations` of length `n`, where each element represents the position of an existing gas station on the X-axis.
- An integer `k`, representing the number of new gas stations you can add.

Your goal is to **add these `k` stations optimally** such that the **maximum distance between any two adjacent stations is minimized**.

🛠️ You may place the gas stations **anywhere on the non-negative X-axis**, including non-integer positions.

---

## 🧪 Sample Input & Output

### ✅ Sample Input:
```
5 4
1 2 3 4 5
```

### ✅ Expected Output:
```
0.500000
```

Explanation: Placing new stations between existing ones reduces the maximum gap to 0.5, which is the minimum possible.

---

## ⚙️ Algorithm Used

- **Binary Search** on the answer space (`low = 0`, `high = max adjacent gap`)
- For each midpoint `mid`, calculate how many gas stations are required to ensure no adjacent distance exceeds `mid`
- Adjust the search space based on whether the required gas stations exceed `k`
- Terminate when the desired precision `1e-6` is achieved

---

## 📌 Time & Space Complexity

- **Time Complexity**: `O(n * log(A / ε))`  
  Where `A` is the max difference between stations and `ε` is the precision (1e-6)
  
- **Space Complexity**: `O(1)` (ignoring input storage)
