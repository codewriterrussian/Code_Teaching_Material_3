# APCS 程式識讀相似練習題（C）

> 共 30 題。題型對應 APCS 程式識讀範例題，但程式、數值與測資皆重新設計。  
> 建議：先手算，再用 trace table 驗證。不要先執行程式。

---

## Q1. 遞迴與正負號

```c
int f(int i) {
    if (i <= 0)
        return 1;

    if (((i / 2) % 2) == 0)
        return i * f(i - 2);
    else
        return -i * f(i - 2);
}
```

`f(8)` 的回傳值為何？

- (A) 384
- (B) -384
- (C) 192
- (D) -192

---

## Q2. 巢狀迴圈與輸出

```c
for (int i = 1; i <= 4; i++) {
    for (int j = 1; ______; j += 2) {
        printf("[%d]", i + j);
    }
}
```

若輸出為：

```text
[2][3][4][6][5][7]
```

空格應填入：

- (A) `j <= i`
- (B) `j < i`
- (C) `j >= i`
- (D) `j != i`

---

## Q3. 遞迴與整數除法

```c
int f(int n) {
    if (n < 2)
        return n;
    return n + f(n / 3);
}
```

`f(20)` 為何？

- (A) 26
- (B) 27
- (C) 28
- (D) 29

---

## Q4. Queue 模擬

下面程式使用陣列模擬 Queue：

```c
int Q[100];
int head = 0, tail = 0;
int count = 0;

for (int i = 1; i <= 12; i++)
    Q[tail++] = i;

while (tail - head > 1) {
    int val = Q[head++];
    count++;

    if (count == 2) {
        Q[tail++] = val;
        count = 0;
    }
}

printf("%d\n", Q[head]);
```

最後印出的數字為何？

- (A) 4
- (B) 6
- (C) 8
- (D) 10

---

## Q5. 圖案輸出

```c
int k = 3;
int m = 1;

for (int i = 0; i < 4; i++) {
    for (int j = 0; j < k; j++)
        printf(" ");

    for (int j = 0; j < m; j++)
        printf("*");

    printf("\n");

    k = k - 1;
    m = m + 1;
}
```

希望星號數依序變成：

```text
1, 3, 5, 7
```

最少需要修改幾行？

- (A) 1 行
- (B) 2 行
- (C) 3 行
- (D) 4 行

---

## Q6. Linear Search 與 Binary Search

陣列：

```c
int a[64];

for (int k = 0; k < 64; k++)
    a[k] = 2 * k + 3;
```

搜尋 `value = 45`。

`f1` 使用 linear search，從 `a[0]` 開始逐一比較；  
`f2` 使用標準 binary search：

```c
low = 0;
high = 63;

while (low <= high) {
    mid = (low + high) / 2;

    if (a[mid] == value)
        break;
    else if (a[mid] < value)
        low = mid + 1;
    else
        high = mid - 1;
}
```

若 `n1`、`n2` 分別為兩種方法執行 `a[...] == value` 比較的次數，則：

- (A) `(21, 4)`
- (B) `(21, 5)`
- (C) `(22, 4)`
- (D) `(22, 5)`

---

## Q7. Fibonacci 狀態更新

```c
int a = 0;
int b = 1;

for (int i = 0; i < n; i++) {
    int temp = b;
    ________;
    a = temp;
}

printf("%d\n", a);
```

若此程式要依序產生 Fibonacci 數列，空格應填入：

- (A) `b = a - b;`
- (B) `b = a + b;`
- (C) `b = a * b;`
- (D) `b = temp;`

---

## Q8. 函式互相呼叫

```c
void B(int x);

void A(int x) {
    printf("%d ", x);

    if (x < 3)
        B(x + 1);

    printf("%d ", x);
}

void B(int x) {
    printf("%d ", x);

    if (x < 4)
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
- (D) 最大印出數字為 3

---

## Q9. Euclidean Algorithm

```c
while (j != 0) {
    ________;
    ________;
    ________;
}
```

若要實作最大公因數的輾轉相除法，下面哪一組正確？

- (A)
  ```c
  k = i % j;
  i = j;
  j = k;
  ```
- (B)
  ```c
  i = j;
  j = i % j;
  k = j;
  ```
- (C)
  ```c
  k = i / j;
  i = j;
  j = k;
  ```
- (D)
  ```c
  k = i + j;
  i = j;
  j = k;
  ```

---

## Q10. 巢狀條件判斷

```c
int count = 7;

if (count > 5)
    count += 2;

if (count % 2 == 1)
    count *= 2;
else
    count -= 3;

if (count)
    count -= 5;
else
    count = 100;

printf("%d\n", count);
```

輸出為何？

- (A) 9
- (B) 13
- (C) 18
- (D) 100

---

## Q11. 修正階乘遞迴

```c
int fact(int n) {
    int r = 1;

    if (n >= 0)
        r = n * fact(n - 1);

    return r;
}
```

若要正確計算 `n!`（且 `fact(0) = 1`），最簡單的修正為：

- (A) 把 `n >= 0` 改為 `n > 0`
- (B) 把 `n >= 0` 改為 `n > 1`
- (C) 把 `r = 1` 改為 `r = 0`
- (D) 把 `n - 1` 改為 `n + 1`

---

## Q12. 反推函式參數

```c
void h(int n, int a, int b, int c) {
    int i = n;

    while (i >= a) {
        int p = 12 - b * i;
        printf("%d", p);
        i -= c;
    }
}
```

若呼叫：

```c
h(5, a, b, c);
```

希望輸出：

```text
2468
```

哪一組參數正確？

- (A) `(a,b,c) = (2,2,1)`
- (B) `(a,b,c) = (1,2,2)`
- (C) `(a,b,c) = (2,1,1)`
- (D) `(a,b,c) = (1,1,2)`

---

## Q13. 遞迴加總

```c
int f(int n) {
    if (n >= 5)
        return 1;

    if (n % 2 == 0)
        return 2 + f(n + 1);
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

`g(4)` 為何？

- (A) 13
- (B) 15
- (C) 17
- (D) 19

---

## Q14. Fibonacci 型遞迴

```c
int Mystery(int x) {
    if (x <= 1)
        return x;

    return Mystery(x - 1) + Mystery(x - 2);
}
```

`Mystery(8)` 為何？

- (A) 13
- (B) 21
- (C) 34
- (D) 55

---

## Q15. Array 交換

```c
int a[9] = {2,4,6,8,10,9,7,5,3};
int n = 9;

for (int i = 0; i < n; i++) {
    int t = a[i];
    a[i] = a[n - i - 1];
    a[n - i - 1] = t;
}

for (int i = 0; i <= n / 2; i++)
    printf("%d %d ", a[i], a[n - i - 1]);
```

最後輸出為何？

- (A) `3 2 5 4 7 6 9 8 10 10`
- (B) `2 3 4 5 6 7 8 9 10 10`
- (C) `3 2 4 5 6 7 8 9 10 10`
- (D) `2 3 5 4 7 6 9 8 10 10`

---

## Q16. 反推遞迴終止條件

```c
int F(int a) {
    if (________)
        return 1;

    return F(a - 1) + F(a - 3);
}
```

已知：

```text
F(5) = 13
```

空格應為：

- (A) `a < 3`
- (B) `a < 2`
- (C) `a < 1`
- (D) `a < 0`

---

## Q17. if / else-if 順序

正確成績規則為：

```text
90–100 → A
80–89  → B
70–79  → C
60–69  → D
0–59   → F
```

程式卻寫成：

```c
if (s >= 90)
    grade = 'A';
else if (s >= 80)
    grade = 'B';
else if (s >= 60)
    grade = 'D';
else if (s >= 70)
    grade = 'C';
else
    grade = 'F';
```

若 `s` 為 0 到 100 的整數，共有多少個分數會被錯誤分類？

- (A) 9
- (B) 10
- (C) 11
- (D) 20

---

## Q18. 二維陣列與方向陣列

```c
int maze[5][5] = {
    {1,0,1,0,1},
    {1,1,0,1,0},
    {0,1,1,0,1},
    {1,0,1,1,0},
    {0,1,0,1,1}
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

- (A) 18
- (B) 20
- (C) 22
- (D) 24

---

## Q19. 圖案輸出條件

```c
for (int i = 0; i < 5; i++) {
    int k = 8 - 2 * i;

    while (________) {
        printf("*");
        k--;
    }

    printf("\n");
}
```

若每列星號數應為：

```text
8
6
4
2
0
```

空格應填入：

- (A) `k >= 0`
- (B) `k >= 2`
- (C) `k > 0`
- (D) `k != 1`

---

## Q20. 冗餘程式碼

```c
printf("100: %d\n", Change / 100);
Change = Change % 100;

printf("25: %d\n", Change / 25);
Change = Change % 25;

printf("10: %d\n", Change / 10);
Change = Change % 10;

printf("1: %d\n", Change / 1);
Change = Change % 1;
```

最後哪一行可以刪除，而不影響輸出或後續結果？

- (A) `Change = Change % 100;`
- (B) `Change = Change % 25;`
- (C) `Change = Change % 10;`
- (D) `Change = Change % 1;`

---

## Q21. 遞迴次方

```c
int G(int a, int x) {
    if (x == 0)
        return 1;

    return a * G(a, x - 1);
}
```

`G(2, 8)` 為何？

- (A) 128
- (B) 256
- (C) 512
- (D) 1024

---

## Q22. 用測資抓 Binary Search 邊界 bug

```c
int A[5] = {1, 4, 7, 10, 13};

int Search(int x) {
    int low = 0;
    int high = 4;

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

函式目標是：

> 回傳陣列中「嚴格大於 `x` 的最小元素」。

哪一個測資最能直接顯示此函式有 bug？

- (A) `Search(-1)`
- (B) `Search(4)`
- (C) `Search(9)`
- (D) `Search(13)`

---

## Q23. Recursive GCD

```c
int GCD(int a, int b) {
    int r = a % b;

    if (r == 0)
        return ______;

    return ______;
}
```

正確填法為：

- (A) `a`, `GCD(a,r)`
- (B) `b`, `GCD(b,r)`
- (C) `r`, `GCD(a,b)`
- (D) `b`, `GCD(r,b)`

---

## Q24. 最大值與最小值

假設程式正確找出陣列中的：

```text
p = 最大值
q = 最小值
```

下列哪一項「不一定」成立？

- (A) 所有元素都 `<= p`
- (B) 所有元素都 `>= q`
- (C) `q < p`
- (D) `q <= p`

---

## Q25. Circular Array Index

```c
int X[8];

for (int i = 0; i < 8; i++) {
    int input = i;
    X[(i + 3) % 8] = input;
}
```

最後 `X[0]` 到 `X[7]` 為何？

- (A) `0 1 2 3 4 5 6 7`
- (B) `3 4 5 6 7 0 1 2`
- (C) `5 6 7 0 1 2 3 4`
- (D) `6 7 0 1 2 3 4 5`

---

## Q26. 迴圈執行次數

下列哪一個迴圈 **不是** 剛好執行 15 次？

- (A)
  ```c
  for (int i = 1; i <= 15; i++)
  ```
- (B)
  ```c
  for (int i = 0; i < 30; i += 2)
  ```
- (C)
  ```c
  for (int i = 5; i <= 75; i += 5)
  ```
- (D)
  ```c
  for (int i = 5; i < 75; i += 5)
  ```

---

## Q27. 永遠不會執行的程式碼

```c
while (a < 20)
    a += 4;

if (a < 23)
    a += 3;

if (a <= 22)
    a = 0;
```

假設 `a` 一開始為任意整數，哪一行永遠不會執行？

- (A) `a += 4`
- (B) `a += 3`
- (C) `a = 0`
- (D) 沒有任何一行

---

## Q28. 三層迴圈執行次數

```c
long long x = 0;

for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= i; j++) {
        for (int k = 1; k <= n; k *= 3) {
            x++;
        }
    }
}
```

`x` 最後為何？

- (A) `n(n+1)/2`
- (B) `n(⌊log₃n⌋+1)`
- (C) `n(n+1)(⌊log₃n⌋+1)/2`
- (D) `n²(⌊log₂n⌋+1)`

---

## Q29. 測資設計：max / min bug

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

哪組輸入最能直接暴露 `N` 可能沒有被正確更新的 bug？

- (A) `[20, 10, 30]`
- (B) `[10, 20, 30]`
- (C) `[30, 10, 20]`
- (D) `[20, 30, 10]`

---

## Q30. Prefix Sum

```c
int b[51];
int a[51];

a[0] = 0;

for (int i = 1; i <= 50; i++) {
    b[i] = 2 * i;
    a[i] = a[i - 1] + b[i];
}
```

`a[40] - a[25]` 為何？

- (A) 900
- (B) 930
- (C) 960
- (D) 990

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
