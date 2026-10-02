# APCS 程式識讀相似練習題（二）— 學生版

> 共 30 題。此為第二套練習，題型延續 APCS 程式識讀常見內容，但程式、數值、陣列與測資皆重新設計。  
> 建議先手算，再用 trace table 驗證；不要一開始就直接執行程式。

---

## Q1. 遞迴與正負號

```c
int f(int i) {
    if (i <= 1)
        return 1;

    if (i % 3 == 0)
        return -i * f(i - 2);
    else
        return i * f(i - 2);
}
```

`f(9)` 的回傳值為何？

- (A) 945
- (B) -945
- (C) 315
- (D) -315

---

## Q2. 巢狀迴圈條件

```c
for (int i = 2; i <= 5; i++) {
    for (int j = 0; ________; j += 2) {
        printf("[%d]", i + j);
    }
}
```

若輸出為：

```text
[2][3][5][4][6][5][7][9]
```

空格應填入：

- (A) `j <= i`
- (B) `j < i`
- (C) `j > i`
- (D) `j == i`

---

## Q3. 遞迴與整數除法

```c
int f(int n) {
    if (n < 2)
        return n;

    return n + f(n / 2);
}
```

`f(18)` 為何？

- (A) 32
- (B) 33
- (C) 34
- (D) 35

---

## Q4. Queue 模擬

```c
int Q[100];
int head = 0, tail = 0;
int count = 0;

for (int i = 1; i <= 15; i++)
    Q[tail++] = i;

while (tail - head > 1) {
    int val = Q[head++];
    count++;

    if (count == 3) {
        Q[tail++] = val;
        count = 0;
    }
}

printf("%d\n", Q[head]);
```

最後印出的數字為何？

- (A) 6
- (B) 8
- (C) 9
- (D) 12

---

## Q5. 圖案輸出

```c
int k = 4;
int m = 2;

for (int i = 0; i < 5; i++) {
    for (int j = 0; j < k; j++)
        printf(" ");

    for (int j = 0; j < m; j++)
        printf("*");

    printf("\n");

    k--;
    m++;
}
```

希望每列星號數改成：

```text
2, 4, 6, 8, 10
```

最少需要修改幾行？

- (A) 1 行
- (B) 2 行
- (C) 3 行
- (D) 4 行

---

## Q6. Linear Search 與 Binary Search

```c
int a[80];

for (int k = 0; k < 80; k++)
    a[k] = 4 * k + 2;
```

搜尋：

```text
value = 98
```

Linear Search 從 `a[0]` 開始逐一比較。

Binary Search 使用：

```c
int low = 0;
int high = 79;

while (low <= high) {
    int mid = (low + high) / 2;

    if (a[mid] == value)
        break;
    else if (a[mid] < value)
        low = mid + 1;
    else
        high = mid - 1;
}
```

若 `n1` 與 `n2` 分別表示兩種搜尋中 `a[...] == value` 被比較的次數，則：

- (A) `(24, 4)`
- (B) `(24, 5)`
- (C) `(25, 5)`
- (D) `(25, 4)`

---

## Q7. 狀態更新

```c
int a = 2;
int b = 1;

for (int i = 0; i < n; i++) {
    int temp = a;
    a = b;
    ________;
}
```

若希望每次更新遵守：

```text
(a, b) → (b, a+b)
```

空格應填入：

- (A) `b = temp + b;`
- (B) `b = a + b;`
- (C) `b = temp - b;`
- (D) `b = a;`

---

## Q8. 函式互相呼叫

```c
void B(int x);

void A(int x) {
    printf("%d ", x);

    if (x < 4)
        B(x + 2);

    printf("%d ", x);
}

void B(int x) {
    printf("%d ", x);

    if (x < 5)
        A(x + 1);
}
```

呼叫：

```c
A(1);
```

下列何者錯誤？

- (A) `A` 被呼叫 2 次
- (B) `B` 被呼叫 1 次
- (C) `B` 被呼叫 2 次
- (D) 最大印出的數字為 4

---

## Q9. Euclidean Algorithm

```c
while (b != 0) {
    int r = ________;
    a = ________;
    b = ________;
}
```

若要實作輾轉相除法，正確填法為：

- (A) `a % b`, `b`, `r`
- (B) `a / b`, `b`, `r`
- (C) `a % b`, `r`, `a`
- (D) `a + b`, `b`, `r`

---

## Q10. 條件判斷追蹤

```c
int count = 6;

if (count >= 6)
    count += 5;

if (count % 3 == 2)
    count *= 2;
else
    count -= 4;

if (count > 20)
    count -= 7;
else
    count += 7;

printf("%d\n", count);
```

輸出為何？

- (A) 11
- (B) 15
- (C) 18
- (D) 22

---

## Q11. 修正遞迴總和

```c
int sum(int n) {
    int r = 0;

    if (n >= 0)
        r = n + sum(n - 1);

    return r;
}
```

若希望：

```text
sum(n) = 1 + 2 + ... + n
sum(0) = 0
```

最直接的修正是：

- (A) 把 `n >= 0` 改成 `n > 0`
- (B) 把 `r = 0` 改成 `r = 1`
- (C) 把 `n - 1` 改成 `n + 1`
- (D) 把 `n >= 0` 改成 `n < 0`

---

## Q12. 反推函式參數

```c
void h(int n, int a, int b, int c) {
    int i = n;

    while (i >= a) {
        int p = 15 - b * i;
        printf("%d", p);
        i -= c;
    }
}
```

若：

```c
h(6, a, b, c);
```

希望輸出：

```text
3579
```

哪組參數正確？

- (A) `(3,2,1)`
- (B) `(2,2,1)`
- (C) `(3,1,1)`
- (D) `(2,2,2)`

---

## Q13. 遞迴加總

```c
int f(int n) {
    if (n >= 6)
        return 2;

    if (n % 2 == 0)
        return 3 + f(n + 1);
    else
        return 1 + f(n + 1);
}

int g(int n) {
    int sum = 0;

    for (int i = 1; i < n; i++)
        sum += f(i);

    return sum;
}
```

`g(5)` 為何？

- (A) 30
- (B) 32
- (C) 34
- (D) 36

---

## Q14. 非標準遞迴

```c
int M(int x) {
    if (x <= 2)
        return 1;

    return M(x - 1) + M(x - 3);
}
```

`M(7)` 為何？

- (A) 7
- (B) 8
- (C) 9
- (D) 10

---

## Q15. Array 反轉與輸出

```c
int a[7] = {1,4,7,10,13,16,19};
int n = 7;

for (int i = 0; i < n / 2; i++) {
    int t = a[i];
    a[i] = a[n - i - 1];
    a[n - i - 1] = t;
}

for (int i = 0; i <= n / 2; i++)
    printf("%d %d ", a[i], a[n - i - 1]);
```

最後輸出為何？

- (A) `1 19 4 16 7 13 10 10`
- (B) `19 1 16 4 13 7 10 10`
- (C) `19 1 13 7 16 4 10 10`
- (D) `10 10 13 7 16 4 19 1`

---

## Q16. 反推遞迴終止條件

```c
int F(int a) {
    if (________)
        return 1;

    return F(a - 2) + F(a - 4);
}
```

已知：

```text
F(6) = 8
```

空格應為：

- (A) `a < 3`
- (B) `a < 2`
- (C) `a < 1`
- (D) `a < 0`

---

## Q17. 成績分類錯誤

正確規則：

```text
90–100 → A
80–89  → B
70–79  → C
60–69  → D
50–59  → E
0–49   → F
```

程式寫成：

```c
if (s >= 90)
    grade = 'A';
else if (s >= 80)
    grade = 'B';
else if (s >= 50)
    grade = 'E';
else if (s >= 70)
    grade = 'C';
else if (s >= 60)
    grade = 'D';
else
    grade = 'F';
```

若 `s` 是 0 到 100 的整數，共有多少個分數會分類錯誤？

- (A) 10
- (B) 20
- (C) 21
- (D) 30

---

## Q18. 二維陣列與方向陣列

```c
int maze[5][5] = {
    {0,1,0,1,0},
    {1,0,1,1,1},
    {0,1,0,1,0},
    {1,1,1,0,1},
    {0,0,1,1,0}
};

int d[4][2] = {
    {-1,0}, {0,1}, {1,0}, {0,-1}
};

int count = 0;

for (int i = 1; i <= 3; i++) {
    for (int j = 1; j <= 3; j++) {
        for (int k = 0; k < 4; k++) {
            int ni = i + d[k][0];
            int nj = j + d[k][1];

            if (maze[ni][nj] == 1)
                count++;
        }
    }
}
```

最後 `count` 為何？

- (A) 20
- (B) 22
- (C) 24
- (D) 26

---

## Q19. 圖案迴圈條件

```c
for (int i = 0; i < 6; i++) {
    int k = 10 - 2 * i;

    while (________) {
        printf("*");
        k--;
    }

    printf("\n");
}
```

希望每列星號數為：

```text
10
8
6
4
2
0
```

空格應填入：

- (A) `k >= 0`
- (B) `k > 1`
- (C) `k != 0`
- (D) `k < 0`

---

## Q20. 找出冗餘程式碼

```c
printf("200: %d\n", Change / 200);
Change = Change % 200;

printf("50: %d\n", Change / 50);
Change = Change % 50;

printf("20: %d\n", Change / 20);
Change = Change % 20;

printf("5: %d\n", Change / 5);
Change = Change % 5;
```

若這已是函式最後一段程式碼，下列哪一行可以刪除而不影響輸出？

- (A) `Change = Change % 200;`
- (B) `Change = Change % 50;`
- (C) `Change = Change % 20;`
- (D) `Change = Change % 5;`

---

## Q21. 遞迴次方

```c
int G(int a, int x) {
    if (x == 0)
        return 1;

    return a * G(a, x - 1);
}
```

`G(3,5)` 為何？

- (A) 81
- (B) 162
- (C) 243
- (D) 729

---

## Q22. Binary Search 邊界測資

```c
int A[6] = {2,5,8,11,14,17};

int Search(int x) {
    int low = 0;
    int high = 5;

    while (low < high) {
        int mid = (low + high) / 2;

        if (A[mid] > x)
            high = mid;
        else
            low = mid + 1;
    }

    return A[high];
}
```

函式目標為：

> 回傳陣列中「嚴格大於 x 的最小元素」。

哪個測資最能直接顯示 bug？

- (A) `Search(1)`
- (B) `Search(5)`
- (C) `Search(12)`
- (D) `Search(17)`

---

## Q23. Recursive GCD

```c
int GCD(int a, int b) {
    int r = a % b;

    if (r == 0)
        return ________;

    return ________;
}
```

正確填法：

- (A) `a`, `GCD(a,r)`
- (B) `b`, `GCD(b,r)`
- (C) `r`, `GCD(r,a)`
- (D) `a`, `GCD(r,b)`

---

## Q24. 最大值與最小值

已知程式正確找出：

```text
p = 陣列最大值
q = 陣列最小值
```

下列哪一個敘述不一定正確？

- (A) `q <= p`
- (B) 每個元素都 `<= p`
- (C) `q < p`
- (D) 每個元素都 `>= q`

---

## Q25. Circular Array Index

```c
int X[10];

for (int i = 0; i < 10; i++)
    X[(i + 5) % 10] = i;
```

最後 `X[0]` 到 `X[9]` 為何？

- (A) `0 1 2 3 4 5 6 7 8 9`
- (B) `4 5 6 7 8 9 0 1 2 3`
- (C) `5 6 7 8 9 0 1 2 3 4`
- (D) `6 7 8 9 0 1 2 3 4 5`

---

## Q26. 迴圈執行次數

下列哪個迴圈不是剛好執行 12 次？

- (A)
  ```c
  for (int i = 0; i < 12; i++)
  ```
- (B)
  ```c
  for (int i = 3; i <= 36; i += 3)
  ```
- (C)
  ```c
  for (int i = 0; i < 24; i += 2)
  ```
- (D)
  ```c
  for (int i = 2; i < 24; i += 2)
  ```

---

## Q27. 永遠不會執行的程式碼

```c
while (a < 30)
    a += 6;

if (a < 35)
    a += 5;

if (a <= 34)
    a = 1;
```

假設 `a` 一開始為任意整數，哪一行永遠不會執行？

- (A) `a += 6`
- (B) `a += 5`
- (C) `a = 1`
- (D) 三行都有可能執行

---

## Q28. 三層迴圈與複雜度

```c
long long x = 0;

for (int i = 1; i <= n; i++) {
    for (int j = i; j <= n; j++) {
        for (int k = 1; k <= n; k *= 4) {
            x++;
        }
    }
}
```

`x` 最後等於：

- (A) `n(n+1)/2`
- (B) `n(n+1)(⌊log₄n⌋+1)/2`
- (C) `n²(⌊log₄n⌋+1)`
- (D) `n(⌊log₄n⌋+1)`

---

## Q29. 測資設計：max/min bug

```c
int M = -1;
int N = 101;

for (int i = 0; i < 3; i++) {
    if (A[i] > M)
        M = A[i];
    else if (A[i] < N)
        N = A[i];
}
```

哪一組輸入最能直接顯示 `N` 沒有被正確更新？

- (A) `[25,15,35]`
- (B) `[15,25,35]`
- (C) `[35,15,25]`
- (D) `[25,35,15]`

---

## Q30. Prefix Sum

```c
int b[46];
int a[46];

a[0] = 0;

for (int i = 1; i <= 45; i++) {
    b[i] = 3 * i;
    a[i] = a[i - 1] + b[i];
}
```

`a[45] - a[30]` 為何？

- (A) 1650
- (B) 1680
- (C) 1710
- (D) 1740

---

# 作答區

```text
01 __   02 __   03 __   04 __   05 __
06 __   07 __   08 __   09 __   10 __
11 __   12 __   13 __   14 __   15 __
16 __   17 __   18 __   19 __   20 __
21 __   22 __   23 __   24 __   25 __
26 __   27 __   28 __   29 __   30 __
```
