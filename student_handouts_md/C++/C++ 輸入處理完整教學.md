## ZeroJudge C++ 輸入處理完整教學

很多同學不是不會寫計算，而是看到 ZeroJudge 的「輸入說明」後，不知道應該怎麼把資料讀進程式。

這一課不會先處理複雜演算法，而是專門練習：

> **看到輸入格式 → 判斷資料結構 → 選擇正確的讀取方法**

---

## 學習目標

完成本課後，你應該能夠：

1. 使用 `cin` 讀取一個或多個資料。
2. 分辨「一行輸入」與「多行輸入」。
3. 處理第一行給測資組數 `T` 的題目。
4. 讀取一串數字、陣列與矩陣。
5. 使用 `getline()` 讀取包含空格的完整文字。
6. 正確混合使用 `cin` 與 `getline()`。
7. 使用 `while (cin >> ...)` 處理 EOF。
8. 使用 `stringstream` 拆解一整行資料。
9. 根據題目的 Input 說明選擇適合的程式架構。

---

# Section I. ZeroJudge 的輸入是什麼？

在一般程式中，我們可能會寫：

```cpp
cout << "請輸入你的年齡：";
cin >> age;
```

但是在 ZeroJudge 中，**不要輸出提示文字**。

錯誤：

```cpp
cout << "請輸入兩個數字：";
cin >> a >> b;
cout << a + b;
```

正確：

```cpp
cin >> a >> b;
cout << a + b;
```

因為 ZeroJudge 會事先準備測試資料，並自動把資料送進你的程式。

假設測試資料是：

```text
5 10
```

執行：

```cpp
cin >> a >> b;
```

之後：

```text
a = 5
b = 10
```

你不需要讓使用者真的在鍵盤上輸入。

---

# Section II. 讀題時先問五個問題

看到題目的 Input 說明時，先不要急著寫程式。

先回答下面五個問題。

## 問題一：總共有幾個資料？

例如：

```text
輸入一個整數 N
```

代表只需要一個變數：

```cpp
int n;
cin >> n;
```

---

## 問題二：資料型別是什麼？

| 題目文字        | 常用 C++ 型別               |
| ----------- | ----------------------- |
| 整數          | `int`                   |
| 很大的整數       | `long long`             |
| 小數、實數       | `double`                |
| 單一字元        | `char`                  |
| 不含空格的文字     | `string` 搭配 `cin`       |
| 可能包含空格的整行文字 | `string` 搭配 `getline()` |

---

## 問題三：資料是固定數量，還是不固定數量？

固定兩個整數：

```text
輸入兩個整數 a、b
```

```cpp
int a, b;
cin >> a >> b;
```

先給數量 `N`，再給 `N` 個整數：

```text
第一行輸入 N
第二行輸入 N 個整數
```

```cpp
int n;
cin >> n;

for (int i = 0; i < n; i++) {
    int value;
    cin >> value;
}
```

---

## 問題四：空格是不是文字的一部分？

輸入一個名字：

```text
Alice
```

可以使用：

```cpp
string name;
cin >> name;
```

輸入完整句子：

```text
I love C++
```

需要使用：

```cpp
string sentence;
getline(cin, sentence);
```

格式化輸入運算子 `>>` 會利用空白分隔資料；要保留文字中的空白時，應改用 `getline()` 讀取完整的一行。

---

## 問題五：程式什麼時候停止讀取？

常見情況有三種：

### 情況 A：只讀一次

```cpp
cin >> a >> b;
```

### 情況 B：第一行提供測資組數 `T`

```cpp
cin >> t;

for (int i = 0; i < t; i++) {
    // 讀取一組資料
}
```

### 情況 C：一直讀到 EOF

```cpp
while (cin >> a >> b) {
    // 每成功讀到一組資料，就處理一次
}
```

EOF 是 End Of File，表示輸入資料已經結束。

---

# Section III. 最基本的輸入：一個資料

## 3.1 讀取一個整數

輸入：

```text
25
```

程式：

```cpp
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    cout << n;
    return 0;
}
```

資料流：

```text
25 → cin → n
```

---

## 3.2 讀取一個小數

輸入：

```text
3.14
```

程式：

```cpp
#include <iostream>
using namespace std;

int main() {
    double number;
    cin >> number;

    cout << number;
    return 0;
}
```

---

## 3.3 讀取一個不含空格的字串

輸入：

```text
Taiwan
```

程式：

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string text;
    cin >> text;

    cout << text;
    return 0;
}
```

ZeroJudge `a001. 哈囉` 的輸入是一行文字，例如 `world` 或 `C++`，輸出時要在文字前加入指定內容。

完整架構：

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string name;
    cin >> name;

    cout << "hello, " << name;
    return 0;
}
```

---

# Section IV. 一行有多個資料

## 4.1 兩個整數

輸入：

```text
5 10
```

程式：

```cpp
#include <iostream>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    cout << a + b;
    return 0;
}
```

`cin` 會依序讀取資料：

```text
5 10
↓ ↓
a b
```

ZeroJudge `a002. 簡易加法` 的輸入是一行兩個以空白分隔的整數，程式需要輸出兩數之和。

---

## 4.2 一定要在同一行嗎？

不一定。

下面兩種輸入對 `cin >> a >> b;` 來說都可以。

輸入一：

```text
5 10
```

輸入二：

```text
5
10
```

程式都是：

```cpp
int a, b;
cin >> a >> b;
```

對 `cin >>` 來說，空白、換行與 Tab 都可以作為資料之間的分隔。

因此，看到：

```text
第一行有兩個整數
```

不需要特別處理「第一行」。

直接寫：

```cpp
cin >> a >> b;
```

即可。

---

## 4.3 不同型別的資料

輸入：

```text
Alice 15 92.5
```

程式：

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string name;
    int age;
    double score;

    cin >> name >> age >> score;

    cout << name << '\n';
    cout << age << '\n';
    cout << score << '\n';

    return 0;
}
```

資料對應：

| 輸入資料    | 變數      |
| ------- | ------- |
| `Alice` | `name`  |
| `15`    | `age`   |
| `92.5`  | `score` |

---

# Section V. 多行輸入

假設輸入是：

```text
3
10
20
30
```

可以寫：

```cpp
int a, b, c, d;

cin >> a;
cin >> b;
cin >> c;
cin >> d;
```

也可以寫成：

```cpp
cin >> a >> b >> c >> d;
```

因為 `cin` 會忽略資料之間的空白與換行。

但是我們仍然應該根據題目的結構安排變數，讓程式比較容易閱讀。

例如：

```text
第一行輸入學生人數 N
接下來 N 行，每行輸入一位學生的成績
```

適合寫成：

```cpp
int n;
cin >> n;

for (int i = 0; i < n; i++) {
    int score;
    cin >> score;

    cout << "第 " << i + 1 << " 筆資料：" << score << '\n';
}
```

---

# Section VI. 第一行是測資組數 T

這是 ZeroJudge 非常常見的輸入格式。

例如：

```text
3
5 10
2 8
100 200
```

第一行的 `3` 表示：

> 接下來共有三組測試資料。

程式架構：

```cpp
#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int a, b;
        cin >> a >> b;

        cout << a + b << '\n';
    }

    return 0;
}
```

執行順序：

```text
讀取 t = 3

第 1 次迴圈：讀取 5 10
第 2 次迴圈：讀取 2 8
第 3 次迴圈：讀取 100 200
```

---

## 6.1 不要把 T 當成普通資料

輸入：

```text
2
1 2 3 4
1 2 4 8
```

第一個 `2` 不是數列的一部分。

它表示接下來有兩組數列。

ZeroJudge `a005. Eva 的回家作業` 的第一行提供數列數量 `t`，之後每行包含四個整數。

輸入架構：

```cpp
int t;
cin >> t;

for (int i = 0; i < t; i++) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    // 處理目前這一組數列
}
```

完整示範：

```cpp
#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        int fifth;

        if (b - a == c - b) {
            fifth = d + (b - a);
        } else {
            fifth = d * (b / a);
        }

        cout << a << ' '
             << b << ' '
             << c << ' '
             << d << ' '
             << fifth << '\n';
    }

    return 0;
}
```

---

# Section VII. 已知 N，再讀取 N 個數字

輸入：

```text
5
10 20 30 40 50
```

其中：

```text
N = 5
```

所以接下來要讀五個整數。

## 方法一：讀一個、處理一個

```cpp
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int total = 0;

    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;

        total += value;
    }

    cout << total;
    return 0;
}
```

這種方法不需要儲存全部數字。

---

## 方法二：使用陣列

```cpp
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int numbers[1000];

    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }

    for (int i = 0; i < n; i++) {
        cout << numbers[i] << ' ';
    }

    return 0;
}
```

---

## 方法三：使用 vector

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> numbers(n);

    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }

    for (int number : numbers) {
        cout << number << ' ';
    }

    return 0;
}
```

---

## 7.1 輸入不一定真的放在同一行

題目可能寫：

```text
第二行有 N 個整數
```

測試資料可能看起來像：

```text
5
10 20 30 40 50
```

也可能因排版而變成：

```text
5
10 20
30
40 50
```

下面的程式仍然可以正常讀取：

```cpp
for (int i = 0; i < n; i++) {
    cin >> numbers[i];
}
```

因為程式在意的是：

> 總共要讀取幾個資料。

而不是每一個資料實際顯示在哪一行。

---

# Section VIII. 讀取矩陣

輸入：

```text
2 3
1 2 3
4 5 6
```

第一行：

```text
2 3
```

表示矩陣有：

```text
2 列
3 欄
```

程式：

```cpp
#include <iostream>
using namespace std;

int main() {
    int rows, columns;
    cin >> rows >> columns;

    int matrix[100][100];

    for (int row = 0; row < rows; row++) {
        for (int column = 0; column < columns; column++) {
            cin >> matrix[row][column];
        }
    }

    for (int row = 0; row < rows; row++) {
        for (int column = 0; column < columns; column++) {
            cout << matrix[row][column] << ' ';
        }

        cout << '\n';
    }

    return 0;
}
```

讀取順序：

```text
matrix[0][0] = 1
matrix[0][1] = 2
matrix[0][2] = 3
matrix[1][0] = 4
matrix[1][1] = 5
matrix[1][2] = 6
```

---

## 矩陣輸入模板

```cpp
int rows, columns;
cin >> rows >> columns;

for (int row = 0; row < rows; row++) {
    for (int column = 0; column < columns; column++) {
        cin >> matrix[row][column];
    }
}
```

看到以下文字時，通常就要想到雙層迴圈：

```text
接下來有 R 行，每行有 C 個整數
```

---

# Section IX. `cin >> string` 與 `getline()` 的差別

## 9.1 使用 `cin >>`

輸入：

```text
I love C++
```

程式：

```cpp
string text;
cin >> text;

cout << text;
```

輸出：

```text
I
```

因為 `cin >> text` 遇到空格就停止。

---

## 9.2 使用 `getline()`

```cpp
string text;
getline(cin, text);

cout << text;
```

輸出：

```text
I love C++
```

`getline()` 會讀取整行文字，直到遇到換行。

Microsoft 的 C++ 文件也將 `getline()` 說明為讀取一整行的字串函式，並可搭配 `while (getline(...))` 持續讀到輸入結束。

---

## 9.3 ZeroJudge 文字題範例

ZeroJudge `a009. 解碼器` 的輸入是一整行字串，字串中可能包含空格；題目提示也建議使用 `getline(cin, string)` 或逐字元讀取。

基本架構：

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string text;
    getline(cin, text);

    for (char ch : text) {
        cout << static_cast<char>(ch - 7);
    }

    return 0;
}
```

---

# Section X. 混合 `cin` 和 `getline()` 的陷阱

考慮以下輸入：

```text
15
I love C++
```

我們想要：

```text
age = 15
sentence = "I love C++"
```

下面的程式有問題：

```cpp
int age;
string sentence;

cin >> age;
getline(cin, sentence);
```

`sentence` 可能會讀到空字串。

---

## 為什麼？

輸入：

```text
15\n
I love C++\n
```

執行：

```cpp
cin >> age;
```

只取走：

```text
15
```

但第一行後面的換行仍然留在輸入資料流中。

接著：

```cpp
getline(cin, sentence);
```

立刻讀到那個換行，因此得到空字串。

---

## 解決方法一：使用 `cin.ignore()`

```cpp
#include <iostream>
#include <string>
#include <limits>
using namespace std;

int main() {
    int age;
    string sentence;

    cin >> age;

    cin.ignore(
        numeric_limits<streamsize>::max(),
        '\n'
    );

    getline(cin, sentence);

    cout << age << '\n';
    cout << sentence << '\n';

    return 0;
}
```

這段程式會忽略目前這一行剩餘的內容，直到換行為止。

---

## 解決方法二：使用 `getline(cin >> ws, sentence)`

```cpp
int age;
string sentence;

cin >> age;
getline(cin >> ws, sentence);
```

`ws` 會先跳過前面的空白與換行。

完整程式：

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    int age;
    string sentence;

    cin >> age;
    getline(cin >> ws, sentence);

    cout << age << '\n';
    cout << sentence << '\n';

    return 0;
}
```

---

## 注意

如果文字最前面的空格也屬於資料的一部分，就不應該使用 `ws`，而應該使用：

```cpp
cin.ignore(
    numeric_limits<streamsize>::max(),
    '\n'
);

getline(cin, sentence);
```

---

# Section XI. 不知道有幾組資料：讀到 EOF

題目有時會寫：

```text
輸入包含若干組測試資料，直到 EOF 為止。
```

這表示題目不會提供 `T`。

程式必須自己持續讀取，直到沒有資料。

---

## 11.1 每組有兩個整數

輸入：

```text
1 2
10 20
100 200
```

程式：

```cpp
#include <iostream>
using namespace std;

int main() {
    int a, b;

    while (cin >> a >> b) {
        cout << a + b << '\n';
    }

    return 0;
}
```

執行過程：

```text
成功讀到 1 2
輸出 3

成功讀到 10 20
輸出 30

成功讀到 100 200
輸出 300

沒有更多資料
迴圈結束
```

---

## 11.2 錯誤寫法

```cpp
while (!cin.eof()) {
    cin >> a >> b;
    cout << a + b << '\n';
}
```

不要把這個寫法當成預設模板。

因為 `eof()` 通常要在讀取失敗後，才會得知資料已經結束，可能造成最後一組資料被重複處理。

建議直接把讀取放進條件：

```cpp
while (cin >> a >> b) {
    cout << a + b << '\n';
}
```

意思是：

> 只要這次成功讀到 `a` 和 `b`，就執行迴圈內容。

---

## 11.3 每次讀取一整行，直到 EOF

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string line;

    while (getline(cin, line)) {
        cout << line << '\n';
    }

    return 0;
}
```

---

# Section XII. 使用 `stringstream` 拆解一整行

有些題目要求：

1. 先取得完整的一行。
2. 再分析這一行中的資料。

例如輸入：

```text
10 20 30 40
```

可以先讀成：

```cpp
string line;
getline(cin, line);
```

此時：

```text
line = "10 20 30 40"
```

再使用 `stringstream`：

```cpp
stringstream ss(line);
```

從 `ss` 中逐一取出整數：

```cpp
int number;

while (ss >> number) {
    cout << number << '\n';
}
```

---

## 完整程式

```cpp
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main() {
    string line;
    getline(cin, line);

    stringstream ss(line);

    int number;
    int total = 0;

    while (ss >> number) {
        total += number;
    }

    cout << total;
    return 0;
}
```

輸入：

```text
10 20 30 40
```

輸出：

```text
100
```

---

## 12.1 多行搭配 `stringstream`

```cpp
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main() {
    string line;

    while (getline(cin, line)) {
        stringstream ss(line);

        int number;
        int total = 0;

        while (ss >> number) {
            total += number;
        }

        cout << total << '\n';
    }

    return 0;
}
```

輸入：

```text
1 2 3
10 20
100 200 300
```

輸出：

```text
6
30
600
```

---

## 12.2 ZeroJudge EOF 文字輸入

ZeroJudge `a017. 五則運算` 的輸入是若干行直到 EOF，每行包含以空格分隔的運算元與運算子；題目提示可使用 `getline()` 與 `stringstream` 讀取及分析。

只討論輸入處理時，可以先使用：

```cpp
string line;

while (getline(cin, line)) {
    stringstream ss(line);

    string token;

    while (ss >> token) {
        cout << '[' << token << ']';
    }

    cout << '\n';
}
```

輸入：

```text
2 + 3 * 4
2 * ( 3 + 4 ) * 5
```

輸出：

```text
[2][+][3][*][4]
[2][*][(][3][+][4][)][*][5]
```

這裡只是在練習「把運算式切成 token」，還沒有進行真正的運算。

---

# Section XIII. 一次讀取一個字元

## 13.1 使用 `cin >> ch`

```cpp
char ch;
cin >> ch;
```

這個方法通常會跳過前面的空白。

輸入：

```text
A
```

可以讀到：

```text
ch = 'A'
```

---

## 13.2 使用 `cin.get(ch)`

```cpp
char ch;
cin.get(ch);
```

`cin.get(ch)` 可以讀到空格和換行。

逐字讀到 EOF：

```cpp
#include <iostream>
using namespace std;

int main() {
    char ch;

    while (cin.get(ch)) {
        cout << ch;
    }

    return 0;
}
```

適合：

* 字元解碼
* 統計空格
* 統計換行
* 逐字元轉換
* 需要保留原始排版的文字處理

---

# Section XIV. 輸入格式判斷表

| 題目 Input 說明      | 建議寫法                         |
| ---------------- | ---------------------------- |
| 輸入一個整數           | `cin >> n;`                  |
| 輸入兩個整數           | `cin >> a >> b;`             |
| 輸入一個不含空格的字串      | `cin >> text;`               |
| 輸入一整行文字          | `getline(cin, text);`        |
| 第一行是測資組數 T       | `cin >> t;` 加 `for`          |
| 先給 N，再給 N 個數字    | `cin >> n;` 加單層 `for`        |
| 接下來 R 行，每行 C 個數字 | 雙層 `for`                     |
| 若干組資料直到 EOF      | `while (cin >> ...)`         |
| 若干行文字直到 EOF      | `while (getline(cin, line))` |
| 一整行有不固定數量的資料     | `getline()` 加 `stringstream` |
| 需要讀取空格與換行        | `cin.get(ch)`                |

---

# Section XV. 解讀 Input 說明的固定流程

每次做 ZeroJudge 題目，都可以使用下面的方法。

## Step 1：圈出數量

例如：

```text
第一行有一個整數 N
接下來有 N 個整數
```

圈出：

```text
N
N 個整數
```

---

## Step 2：決定變數

```cpp
int n;
int value;
```

---

## Step 3：決定是否需要迴圈

因為有 `N 個整數`：

```cpp
for (int i = 0; i < n; i++) {
    cin >> value;
}
```

---

## Step 4：把輸入架構先寫完

```cpp
int n;
cin >> n;

for (int i = 0; i < n; i++) {
    int value;
    cin >> value;
}
```

---

## Step 5：最後才加入計算

```cpp
int n;
cin >> n;

int total = 0;

for (int i = 0; i < n; i++) {
    int value;
    cin >> value;

    total += value;
}

cout << total;
```

不要同時思考：

* 如何輸入
* 如何計算
* 如何判斷
* 如何輸出

先把 Input 完成，再寫 Process。

---

# Section XVI. IFPO 解題架構

可以把題目分成四個部分：

```text
INPUT → FUNCTION → PROCESS → OUTPUT
```

## INPUT

資料要怎麼讀進來？

```cpp
int n;
cin >> n;
```

## FUNCTION

是否需要函式？

```cpp
int square(int number) {
    return number * number;
}
```

## PROCESS

資料要怎麼計算？

```cpp
int answer = square(n);
```

## OUTPUT

答案要怎麼輸出？

```cpp
cout << answer;
```

完整程式：

```cpp
#include <iostream>
using namespace std;

int square(int number) {
    return number * number;
}

int main() {
    // INPUT
    int n;
    cin >> n;

    // PROCESS
    int answer = square(n);

    // OUTPUT
    cout << answer;

    return 0;
}
```

---

# Section XVII. 常見錯誤

## 錯誤一：輸出提示文字

```cpp
cout << "Please enter a number: ";
cin >> n;
```

ZeroJudge 會把提示文字當成答案的一部分，可能造成 Wrong Answer。

改成：

```cpp
cin >> n;
```

---

## 錯誤二：讀取的資料數量不足

輸入：

```text
5 10
```

錯誤：

```cpp
int a;
cin >> a;
cout << a;
```

題目有兩個整數，卻只讀了一個。

正確：

```cpp
int a, b;
cin >> a >> b;
```

---

## 錯誤三：多讀了一個不存在的資料

輸入只有：

```text
5 10
```

卻寫：

```cpp
int a, b, c;
cin >> a >> b >> c;
```

程式會繼續等待第三個數字，或因輸入結束而讀取失敗。

---

## 錯誤四：把 T 當成普通資料

輸入：

```text
3
10 20
30 40
50 60
```

第一個 `3` 是測資組數，不是第一組資料的 `a`。

正確：

```cpp
int t;
cin >> t;

for (int i = 0; i < t; i++) {
    int a, b;
    cin >> a >> b;
}
```

---

## 錯誤五：用 `cin >>` 讀取完整句子

```cpp
string sentence;
cin >> sentence;
```

輸入：

```text
Hello C++ World
```

只會讀到：

```text
Hello
```

應改成：

```cpp
getline(cin, sentence);
```

---

## 錯誤六：`cin` 後直接使用 `getline()`

錯誤：

```cpp
cin >> n;
getline(cin, sentence);
```

正確：

```cpp
cin >> n;
cin.ignore(
    numeric_limits<streamsize>::max(),
    '\n'
);
getline(cin, sentence);
```

---

## 錯誤七：不知道什麼時候使用 EOF

題目寫：

```text
輸入若干組資料，直到 EOF。
```

卻只寫：

```cpp
cin >> a >> b;
```

這樣只能處理第一組。

正確：

```cpp
while (cin >> a >> b) {
    cout << a + b << '\n';
}
```

---

## 錯誤八：迴圈次數寫錯

要讀 `N` 個數字：

```cpp
for (int i = 0; i <= n; i++)
```

這會執行 `N + 1` 次。

正確：

```cpp
for (int i = 0; i < n; i++)
```

---

# Section XVIII. 除錯方法

學生遇到輸入問題時，可以暫時輸出讀到的內容。

例如：

```cpp
int a, b;
cin >> a >> b;

cerr << "a = " << a << '\n';
cerr << "b = " << b << '\n';

cout << a + b;
```

`cerr` 適合在自己的電腦上協助除錯。

提交前最好移除除錯輸出：

```cpp
cerr << "a = " << a << '\n';
```

---

## 使用固定測資測試

在 IDE 中執行後，貼上：

```text
5 10
```

確認輸出是否為：

```text
15
```

也要測試特殊情況：

```text
0 0
```

```text
-5 10
```

```text
1000000 -1000000
```

---

# Section XIX. 課堂練習

## 練習一：讀取一個整數

輸入一個整數，輸出它的兩倍。

輸入：

```text
8
```

輸出：

```text
16
```

學生版：

```cpp
#include <iostream>
using namespace std;

int main() {
    // TODO：建立一個整數變數

    // TODO：讀取輸入

    // TODO：輸出兩倍

    return 0;
}
```

---

## 練習二：讀取三個整數

輸入三個整數，輸出三數總和。

輸入：

```text
10 20 30
```

輸出：

```text
60
```

學生版：

```cpp
#include <iostream>
using namespace std;

int main() {
    // TODO：建立三個整數變數

    // TODO：讀取三個整數

    // TODO：輸出總和

    return 0;
}
```

---

## 練習三：測資組數

第一行輸入整數 `T`。

接下來有 `T` 組資料，每組包含兩個整數，請輸出每組的乘積。

輸入：

```text
3
2 5
4 6
10 10
```

輸出：

```text
10
24
100
```

學生版：

```cpp
#include <iostream>
using namespace std;

int main() {
    int t;

    // TODO：讀取 t

    // TODO：重複 t 次
    // 每次讀取 a、b
    // 輸出 a * b

    return 0;
}
```

---

## 練習四：N 個整數

第一行輸入 `N`，接著輸入 `N` 個整數，輸出其中的最大值。

輸入：

```text
5
8 3 12 7 10
```

輸出：

```text
12
```

提示：

```cpp
int maximum;
cin >> maximum;
```

可以先讓第一個數字成為目前最大值，再讀取剩下的數字。

---

## 練習五：完整句子

輸入一整行文字，原樣輸出。

輸入：

```text
C++ input is important.
```

輸出：

```text
C++ input is important.
```

學生版：

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string sentence;

    // TODO：讀取完整的一行

    cout << sentence;
    return 0;
}
```

---

## 練習六：混合數字與句子

第一行輸入年齡。

第二行輸入一段自我介紹。

輸入：

```text
15
I am learning C++.
```

輸出：

```text
Age: 15
Introduction: I am learning C++.
```

學生版：

```cpp
#include <iostream>
#include <limits>
#include <string>
using namespace std;

int main() {
    int age;
    string introduction;

    // TODO：讀取 age

    // TODO：清除換行

    // TODO：讀取完整介紹

    cout << "Age: " << age << '\n';
    cout << "Introduction: " << introduction << '\n';

    return 0;
}
```

---

## 練習七：讀到 EOF

每一行包含兩個整數，輸出兩數之差，直到 EOF。

輸入：

```text
10 3
20 8
100 70
```

輸出：

```text
7
12
30
```

學生版：

```cpp
#include <iostream>
using namespace std;

int main() {
    int a, b;

    // TODO：只要能成功讀到 a 和 b，就繼續

    return 0;
}
```

---

## 練習八：矩陣總和

第一行輸入 `R` 和 `C`。

接下來輸入一個 `R × C` 的整數矩陣，輸出所有元素的總和。

輸入：

```text
2 3
1 2 3
4 5 6
```

輸出：

```text
21
```

學生版：

```cpp
#include <iostream>
using namespace std;

int main() {
    int rows, columns;
    int total = 0;

    // TODO：讀取 rows 和 columns

    // TODO：使用雙層迴圈讀取矩陣

    // TODO：把每個數字加到 total

    cout << total;
    return 0;
}
```

---

# Section XX. 練習參考答案

## 練習一

```cpp
#include <iostream>
using namespace std;

int main() {
    int number;
    cin >> number;

    cout << number * 2;
    return 0;
}
```

---

## 練習二

```cpp
#include <iostream>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    cout << a + b + c;
    return 0;
}
```

---

## 練習三

```cpp
#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int a, b;
        cin >> a >> b;

        cout << a * b << '\n';
    }

    return 0;
}
```

---

## 練習四

```cpp
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int maximum;
    cin >> maximum;

    for (int i = 1; i < n; i++) {
        int number;
        cin >> number;

        if (number > maximum) {
            maximum = number;
        }
    }

    cout << maximum;
    return 0;
}
```

---

## 練習五

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string sentence;
    getline(cin, sentence);

    cout << sentence;
    return 0;
}
```

---

## 練習六

```cpp
#include <iostream>
#include <limits>
#include <string>
using namespace std;

int main() {
    int age;
    string introduction;

    cin >> age;

    cin.ignore(
        numeric_limits<streamsize>::max(),
        '\n'
    );

    getline(cin, introduction);

    cout << "Age: " << age << '\n';
    cout << "Introduction: " << introduction << '\n';

    return 0;
}
```

---

## 練習七

```cpp
#include <iostream>
using namespace std;

int main() {
    int a, b;

    while (cin >> a >> b) {
        cout << a - b << '\n';
    }

    return 0;
}
```

---

## 練習八

```cpp
#include <iostream>
using namespace std;

int main() {
    int rows, columns;
    int total = 0;

    cin >> rows >> columns;

    for (int row = 0; row < rows; row++) {
        for (int column = 0; column < columns; column++) {
            int number;
            cin >> number;

            total += number;
        }
    }

    cout << total;
    return 0;
}
```

---

# Section XXI. ZeroJudge 輸入處理速查模板

## 模板一：固定數量

```cpp
int a, b;
cin >> a >> b;
```

## 模板二：T 組資料

```cpp
int t;
cin >> t;

for (int i = 0; i < t; i++) {
    // 讀取一組資料
}
```

## 模板三：N 個數字

```cpp
int n;
cin >> n;

for (int i = 0; i < n; i++) {
    int value;
    cin >> value;
}
```

## 模板四：矩陣

```cpp
int rows, columns;
cin >> rows >> columns;

for (int row = 0; row < rows; row++) {
    for (int column = 0; column < columns; column++) {
        int value;
        cin >> value;
    }
}
```

## 模板五：完整一行

```cpp
string line;
getline(cin, line);
```

## 模板六：`cin` 後使用 `getline()`

```cpp
cin >> n;

cin.ignore(
    numeric_limits<streamsize>::max(),
    '\n'
);

getline(cin, line);
```

## 模板七：讀到 EOF

```cpp
while (cin >> a >> b) {
    // 處理一組資料
}
```

## 模板八：逐行讀到 EOF

```cpp
string line;

while (getline(cin, line)) {
    // 處理目前這一行
}
```

## 模板九：拆解一整行

```cpp
string line;
getline(cin, line);

stringstream ss(line);

int value;

while (ss >> value) {
    // 處理 value
}
```

---

# Section XXII. 最後檢查清單

提交 ZeroJudge 前，逐項確認：

* [ ] 我有讀取題目要求的所有資料。
* [ ] 變數型別符合題目範圍。
* [ ] 第一個數字是不是測資組數 `T`？
* [ ] 題目是否提供資料數量 `N`？
* [ ] 是否需要單層或雙層迴圈？
* [ ] 文字中是否可能包含空格？
* [ ] 是否需要使用 `getline()`？
* [ ] 是否混合使用了 `cin` 和 `getline()`？
* [ ] 題目是否要求讀到 EOF？
* [ ] 我有沒有輸出不必要的提示文字？
* [ ] 每組答案是否需要換行？
* [ ] 迴圈應該使用 `< n`，還是其他條件？
* [ ] 我是否先完成 Input，再處理計算？

---

# 本課核心觀念

不要只背：

```cpp
cin >> a;
```

真正需要學會的是：

```text
題目給了什麼資料？
→ 資料有幾個？
→ 資料是什麼型別？
→ 是否重複？
→ 是否包含空格？
→ 何時停止讀取？
→ 選擇 cin、getline、for、while 或 stringstream
```

只要能正確把題目的 Input 說明翻譯成程式架構，大部分基礎 ZeroJudge 題目的輸入問題就已經解決了一半。
