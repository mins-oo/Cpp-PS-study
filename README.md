# 💻 C++ Study
<details>
  <summary>백준 잡담</summary>
<div>
  <p>Baekjoon 단계별 풀이 및 기타 문제들을 푼다. 나중에 복기하기 위해 테마별로 기록했다. </p>
  <h3>Using Language : C++</h3>
</div>
<div align=center>
  
  [![Solved.ac Profile](http://mazassumnida.wtf/api/v2/generate_badge?boj=msjhkim04)](https://solved.ac/msjhkim04/)<a href="https://www.acmicpc.net/" title="[baekjoon](https://www.acmicpc.net/)으로 이동" target="_blank">백준열기</a>
  
</div>
<details>
  <summary>일기장</summary>
  <h3>2025.07.03</h3>
  <p>군대에서 핸드폰 시간동안 문제들을 캡쳐해 에어드랍으로 아이패드에 옮기고 '모바일 C'라는 앱으로 코드 작성 및 컴파일을 한다. 휴가나와서 지금까지 풀었던 문제들을 깃허브에 업로드 했다. 대략 25년 3월 말부터 시작한 문제풀이들이다.</p>

  <h3>2025.10.12</h3>
  <p>한동안 안 하다 다시 시작. 파일을 정리하고 기록하는데 가독성이 있으면 좋겠다 싶어 문제들을 백준에서 제시하는 단계의 이름이 아닌, 유형별로 정리했다.</p>
  
  <h3>2025.11.17</h3>
  <p>종만북을 토대로 알고리즘 공부를 하다가 다이나믹 프로그래밍 파트를 접하게 되었다. 그중 memoization 개념이 재미있어 다이나믹 프로그래밍 관련 문제를 풀어봤다.</p>

  <h3>2025.12.08</h3>
  <p>휴가 나와서 readme, profile 꾸미기를 알게되었다. 새벽에 재밌게 갖고 노는 중...</p>
</details>
</details>

# 고급프로그래밍 중간고사 정리 (Ch01~Ch09)

---

## Ch02 - 순차문과 반복문

### 파일 입출력 (fstream)
**파일:** `Ch02/02-11.cpp`

```cpp
#include <fstream>

int main() {
    fstream inputStream;
    inputStream.open("player.txt");
    
    int score;
    string firstName, lastName;
    inputStream >> score;
    inputStream >> firstName >> lastName;
    
    inputStream.close();
    return 0;
}
```

**주의할점:**
- `open()`으로 파일 열기
- `>>` 연산자로 파일에서 읽기
- 사용 후 `close()`로 파일 닫기

---

## Ch03 - 출력 형식과 함수

### cout 출력 형식
**파일:** `Ch03/03-01.cpp`

```cpp
cout.setf(ios::fixed);      // 고정 소수점 표기
cout.setf(ios::showpoint);  // 소수점 항상 표시
cout.precision(2);          // 소수점 아래 2자리
cout << "$" << budget << endl;
```

**주의할점:**
- `ios::fixed`: 0.12 대신 0.12 출력
- `ios::showpoint`: 5.0 대신 5.00 출력
- `precision(n)`: 유효 자릿수 설정

---

### round 함수 구현
**파일:** `Ch03/03-06.cpp`

```cpp
#include <cmath>

int round(double number) {
    return static_cast<int>(floor(number + 0.5));
}
```

**주의할점:**
- `floor()`: 소수점 아래 버림
- `static_cast<int>`: double을 int로 변환
- number가 음수일 때는 다른 처리 필요

---

## Ch04 - 함수와 참조

### Swap 함수 (참조 사용)
**파일:** `Ch04/04-02.cpp`, `Ch04/04-04.cpp`

```cpp
void swap(int& v1, int& v2) {
    int temp = v1;
    v1 = v2;
    v2 = temp;
}

// 사용
int x = 1, y = 2;
swap(x, y);  // x=2, y=1
```

**주의할점:**
- 참조(`&`) 없이는 원본 변경 불가 (값 복사)
- temp 변수로 값 교환

---

## Ch05 - 배열과 포인터

### fillArray 함수
**파일:** `Ch05/05-05.cpp`, `Ch05/05-06.cpp`, `Ch05/05-08.cpp`

```cpp
void fillArray(int a[], int size, int& numberUsed) {
    cout << "Enter up to " << size << " nonnegative whole numbers.\n"
         << "Mark the end of the list with a negative number.\n";

    int next, index = 0;
    cin >> next;
    while ((next >= 0) && (index < size)) {
        a[index] = next;
        index++;
        cin >> next;
    }
    numberUsed = index;
}
```

**주의할점:**
- `size`: 배열의 최대 크기
- `numberUsed`: 실제 입력된 개수 (참조로 반환)
- 반복 조건: `next >= 0 && index < size`

---

### search 함수
**파일:** `Ch05/05-06.cpp`

```cpp
int search(const int a[], int numberUsed, int target) {
    int index = 0;
    bool found = false;
    while ((!found) && (index < numberUsed))
        if (target == a[index])
            found = true;
        else
            index++;

    if (found)
        return index;
    else
        return -1;
}
```

**주의할점:**
- 선형 검색 (순차 탐색)
- 찾지 못하면 `-1` 반환

---

### indexOfSmallest 함수
**파일:** `Ch05/05-08.cpp`

```cpp
int indexOfSmallest(const int a[], int startIndex, int numberUsed) {
    int min = a[startIndex], indexOfMin = startIndex;
    for (int index = startIndex + 1; index < numberUsed; index++)
        if (a[index] < min) {
            min = a[index];
            indexOfMin = index;
        }
    return indexOfMin;
}
```

---

### sort 함수 (Selection Sort)
**파일:** `Ch05/05-08.cpp`

```cpp
void sort(int a[], int numberUsed) {
    int indexOfNextSmallest;
    for (int index = 0; index < numberUsed - 1; index++) {
        indexOfNextSmallest = indexOfSmallest(a, index, numberUsed);
        swapValues(a[index], a[indexOfNextSmallest]);
    }
}
```

**알고리즘:**
1. 남은 요소 중 가장 작은 선택
2. 현재 위치와 교환
3. 다음 위치로 이동

---

### Bubble Sort
**파일:** `Ch05/05-09.cpp`

```cpp
void bubblesort(int arr[], int length) {
    for (int i = length - 1; i > 0; i--)
        for (int j = 0; j < i; j++)
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
            }
}
```

**알고리즘:**
- 바깥 루프: 뒤에서부터 진행
- 안쪽 루프: 0부터 i까지 인접 요소 비교 및 교환
- 가장 큰 값이 오른쪽으로 "버블링"

---

## Ch07 - 클래스와 객체

### 클래스 정의
**파일:** `Ch07/07-01.cpp`

```cpp
class DayOfYear {
public:
    DayOfYear(int monthValue, int dayValue);
    DayOfYear(int monthValue);
    DayOfYear();
    void input();
    void output();
    int getMonthNumber();
    int getDay();
private:
    int month;
    int day;
    void testDate();
};
```

**주의할점:**
- `public`: 외부에서 접근 가능
- `private`: 클래스 내부에서만 접근
- 기본값 private (class 키워드使用时)

---

### 생성자 (Constructor)
**파일:** `Ch07/07-01.cpp`

```cpp
// 생성자 정의
DayOfYear::DayOfYear(int monthValue, int dayValue) : month(monthValue), day(dayValue) {
    testDate();
}

DayOfYear::DayOfYear(int monthValue) : month(monthValue), day(1) {
    testDate();
}

DayOfYear::DayOfYear() : month(1), day(1) {/*empty*/}

// 사용
DayOfYear date1(2, 21);  // 2월 21일
DayOfYear date2(5);     // 5월 1일
DayOfYear date3;        // 1월 1일
```

**주의할점:**
- 생성자 이름은 클래스명과 동일
- 반환 타입 없음
- 초기화 목록 `: month(value)` 사용 가능

---

### BankAccount 클래스
**파일:** `Ch07/07-02.cpp`, `Ch07/07-04.cpp`, `Ch07/07-05.cpp`

```cpp
class BankAccount {
public:
    BankAccount(double balance, double rate);
    BankAccount(int dollars, int cents, double rate);
    BankAccount(int dollars, double rate);
    BankAccount();  // $0.00, 0.0%

    void update();   // 이자 추가
    void input();
    void output() const;
    double getBalance() const;
    int getDollars() const;
    int getCents() const;
    void setBalance(double balance);
    void setBalance(int dollars, int cents);
    void setRate(double newRate);
private:
    int accountDollars;
    int accountCents;
    double rate;
    int dollarsPart(double amount) const;
    int centsPart(double amount) const;
    int round(double number) const;
    double fraction(double percent) const;
};

// 생성자 구현
BankAccount::BankAccount(double balance, double rate)
 : accountDollars(dollarsPart(balance)), accountCents(centsPart(balance)) {
    setRate(rate);
}
```

**주의할점:**
- 음수 잔액: dollars와 cents 모두 음수 (예: -4, -50 = -$4.50)
- dollars와 cents 부호가 다르면 에러 발생

---

### 정적 변수와 정적 함수
**파일:** `Ch07/07-06.cpp`

```cpp
class Server {
public:
    Server(char letterName);
    static int getTurn();
    static void serveOne();
    static bool stillOpen();
private:
    static int turn;        // 모든 객체가 공유
    static int lastServed;
    static bool nowOpen;
    char name;
};

// 정의 (클래스 외부에서)
int Server::turn = 0;
int Server::lastServed = 0;
bool Server::nowOpen = true;

// 정적 함수 구현
int Server::getTurn() {
    turn++;
    return turn;
}

bool Server::stillOpen() {
    return nowOpen;
}
```

**주의할점:**
- 정적 함수는 non-static 멤버 변수 접근 불가
- 객체 생성 없이 `Server::getTurn()` 호출 가능
- 모든 객체가 정적 변수 공유

---

## Ch08 - 연산자 오버로딩

### 멤버 함수로 연산자 정의
**파일:** `Ch08/08-02.cpp`

```cpp
class Money {
public:
    const Money operator +(const Money& amount2) const;
    const Money operator -(const Money& amount2) const;
    bool operator ==(const Money& amount2) const;
    const Money operator -() const;  // 단항 마이너스
private:
    int dollars;
    int cents;
};

const Money Money::operator +(const Money& secondOperand) const {
    int allCents1 = cents + dollars * 100;
    int allCents2 = secondOperand.cents + secondOperand.dollars * 100;
    int sumAllCents = allCents1 + allCents2;
    int absAllCents = abs(sumAllCents);
    int finalDollars = absAllCents / 100;
    int finalCents = absAllCents % 100;

    if (sumAllCents < 0) {
        finalDollars = -finalDollars;
        finalCents = -finalCents;
    }
    return Money(finalDollars, finalCents);
}

bool Money::operator ==(const Money& secondOperand) const {
    return ((dollars == secondOperand.dollars)
            && (cents == secondOperand.cents));
}

const Money Money::operator -() const {  // 단항
    return Money(-dollars, -cents);
}
```

---

### friend 함수로 연산자 정의
**파일:** `Ch08/08-01.cpp`, `Ch08/08-03.cpp`

```cpp
class Money {
    friend const Money operator +(const Money& amount1, const Money& amount2);
    friend const Money operator -(const Money& amount1, const Money& amount2);
    friend bool operator ==(const Money& amount1, const Money& amount2);
    friend const Money operator -(const Money& amount);
};

const Money operator +(const Money& amount1, const Money& amount2) {
    int allCents1 = amount1.getCents() + amount1.getDollars() * 100;
    int allCents2 = amount2.getCents() + amount2.getDollars() * 100;
    // ... 같은 로직
}

const Money operator -(const Money& amount1, const Money& amount2) {
    int allCents1 = amount1.getCents() + amount1.getDollars() * 100;
    int allCents2 = amount2.getCents() + amount2.getDollars() * 100;
    int diffAllCents = allCents1 - allCents2;
    int absAllCents = abs(diffAllCents);
    int finalDollars = absAllCents / 100;
    int finalCents = absAllCents % 100;

    if (diffAllCents < 0) {
        finalDollars = -finalDollars;
        finalCents = -finalCents;
    }
    return Money(finalDollars, finalCents);
}
```

**주의할점:**
- friend 함수는 private 멤버에 직접 접근 가능
- getter 함수 없어도 amount.dollars 접근 가능

---

### 입출력 연산자 오버로딩
**파일:** `Ch08/08-05.cpp`

```cpp
class Money {
    friend ostream& operator <<(ostream& outputStream, const Money& amount);
    friend istream& operator >>(istream& inputStream, Money& amount);
};

ostream& operator <<(ostream& outputStream, const Money& amount) {
    int absDollars = abs(amount.dollars);
    int absCents = abs(amount.cents);
    if (amount.dollars < 0 || amount.cents < 0)
        outputStream << "$-";
    else
        outputStream << '$';
    outputStream << absDollars;
    if (absCents >= 10)
        outputStream << '.' << absCents;
    else
        outputStream << '.' << '0' << absCents;
    return outputStream;
}

istream& operator >>(istream& inputStream, Money& amount) {
    char dollarSign;
    inputStream >> dollarSign;
    if (dollarSign != '$') {
        cout << "No dollar sign in Money input.\n";
        exit(1);
    }
    double amountAsDouble;
    inputStream >> amountAsDouble;
    amount.dollars = amount.dollarsPart(amountAsDouble);
    amount.cents = amount.centsPart(amountAsDouble);
    return inputStream;
}
```

**주의할점:**
- 반환 타입이 `ostream&`/`istream&` (연속 출력 가능)
- 입력 시 `$` 기호 확인 필요

---

### 전위/후위 증가연산자
**파일:** `Ch08/08-06.cpp`

```cpp
class IntPair {
public:
    IntPair(int firstValue, int secondValue);
    IntPair operator++();        // 전위 (Prefix)
    IntPair operator++(int);     // 후위 (Postfix)
private:
    int first;
    int second;
};

// 전위: 먼저 증가, 후 반환
IntPair IntPair::operator++() {
    first++;
    second++;
    return IntPair(first, second);
}

// 후위: 현재 값 저장, 증가, 저장된 값 반환
IntPair IntPair::operator++(int ignoreMe) {
    int temp1 = first;
    int temp2 = second;
    first++;
    second++;
    return IntPair(temp1, temp2);
}
```

**주의할점:**
- 후위는 `int` 파라미터로 전위와 구분
- 후위는 증가 전 값을 반환 (임시 객체)

---

## Ch09 - 문자열 처리

### string 메서드
**파일:** `Ch09/09-06.cpp`

```cpp
string str = "Hello";
int len = str.length();        // 문자열 길이 (5)
char c = str[0];               // 'H'
str[0] = 'J';                  // 수정 가능 (str = "Jello")
```

**주의할점:**
- `length()`: 문자 개수 반환
- `[]`: 배열처럼 접근 가능 (수정 가능)

---

### 회문 검사 관련 함수
**파일:** `Ch09/09-08.cpp`

```cpp
#include <cctype>  // tolower 사용

// swap 함수
void swap(char& v1, char& v2) {
    char temp = v1;
    v1 = v2;
    v2 = temp;
}

// reverse: 문자열 뒤집기
string reverse(const string& s) {
    int start = 0;
    int end = s.length();
    string temp(s);

    while (start < end) {
        end--;
        swap(temp[start], temp[end]);
        start++;
    }
    return temp;
}

// makeLower: 대문자 -> 소문자
string makeLower(const string& s) {
    string temp(s);
    for (int i = 0; i < s.length(); i++)
        temp[i] = tolower(s[i]);
    return temp;
}

// removePunct: 구두점 제거
string removePunct(const string& s, const string& punct) {
    string noPunct;
    int sLength = s.length();

    for (int i = 0; i < sLength; i++) {
        string aChar = s.substr(i, 1);
        int location = punct.find(aChar, 0);
        if (location < 0 || location >= punct.length())
            noPunct = noPunct + aChar;
    }
    return noPunct;
}

// isPal: 회문 검사
bool isPal(const string& s) {
    string punct(",;:.?!'\" ");
    string str(s);
    str = makeLower(str);
    string lowerStr = removePunct(str, punct);
    return (lowerStr == reverse(lowerStr));
}
```

**주요 함수 정리:**

| 함수 | 설명 | 예시 |
|------|------|------|
| `length()` | 문자열 길이 | `"hello".length()` → 5 |
| `substr(i, n)` | i부터 n개 추출 | `"hello".substr(1, 3)` → "ell" |
| `find(s, start)` | s 위치 탐색, 없으면 -1 | `"hello".find("l", 0)` → 2 |
| `tolower(c)` | 소문자 변환 | `tolower('A')` → 'a' |

---

## 중요 라이브러리 정리

### string
```cpp
#include <string>
string s = "hello";
s.length(); s.substr(i, n); s.find(str, start);
```

### cctype
```cpp
#include <cctype>
tolower(c); toupper(c);  // 문자 변환
isalpha(c); isdigit(c);  // 문자 분류
```

### cmath
```cpp
#include <cmath>
floor(x); ceil(x); sqrt(x); abs(x);
```

### cstring
```cpp
#include <cstring>
```

**주요 함수:**

| 함수 | 설명 | 예시 |
|------|------|------|
| `strlen(s)` | 문자열 길이 반환 | `strlen("hello")` → 5 |
| `strcmp(s1, s2)` | 문자열 비교 (0=같음) | `strcmp("abc", "abc")` → 0 |
| `strcpy(s1, s2)` | 문자열 복사 | `strcpy(dest, src)` |
| `strcat(s1, s2)` | 문자열 연결 | `strcat(s1, s2)` → s1에 s2 연결 |
| `strncpy(s1, s2, n)` | n개 문자만 복사 | `strncpy(dest, src, 3)` |
| `strstr(s1, s2)` | s2가 s1에 있으면 포인터 반환 | `strstr("hello", "ell")` → "ello" 포인터 |

**주의할점:**
- `strcmp` 반환값: 0=같음, 음수=s1<s2, 양수=s1>s2
- `strcpy`/`strcat`은 대상 문자열 버퍼 크기 확인 필요
- C-string은 `'\0'`로 종료됨
- `string` 대신 C-style 문자열 처리 시 사용

---
