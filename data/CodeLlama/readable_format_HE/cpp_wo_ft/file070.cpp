#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> numerical_letter_grade(const vector<double> &grades) {
    vector<string> out(grades.size());

    for (int i = 0; i < grades.size(); i++) {
        if (grades[i] >= 3.9999) {
            out[i] = "A+";
        } else if (grades[i] > 3.7001 && grades[i] < 3.9999) {
            out[i] = "A ";
        } else if (grades[i] > 3.3001 && grades[i] <= 3.7001) {
            out[i] = "A-";
        } else if (grades[i] > 3.0001 && grades[i] <= 3.3001) {
            out[i] = "B+";
        } else if (grades[i] > 2.7001 && grades[i] <= 3.0001) {
            out[i] = "B ";
        } else if (grades[i] > 2.3001 && grades[i] <= 2.7001) {
            out[i] = "B-";
        } else if (grades[i] > 2.0001 && grades[i] <= 2.3001) {
            out[i] = "C+";
        } else if (grades[i] > 1.7001 && grades[i] <= 2.0001) {
            out[i] = "C ";
        } else if (grades[i] > 1.3001 && grades[i] <= 1.7001) {
            out[i] = "C-";
        } else if (grades[i] > 1.0001 && grades[i] <= 1.3001) {
            out[i] = "D+";
        } else if (grades[i] > 0.7001 && grades[i] <= 1.0001) {
            out[i] = "D ";
        } else if (grades[i] > 0.0001 && grades[i] <= 0.7001) {
            out[i] = "D-";
        } else {
            out[i] = "E ";
        }
    }

    return out;
}

int main() {
    vector<double> grades1 = {4.0, 3.0, 1.7, 2.0, 3.5};
    vector<string> expected1 = {"A+", "B ", "C-", "C ", "A-"};
    if (numerical_letter_grade(grades1) != expected1) {
        cout << "Assertion failed for test case 1" << endl;
        return 1;
    }

    vector<double> grades2 = {1.2};
    vector<string> expected2 = {"D+"};
    if (numerical_letter_grade(grades2) != expected2) {
        cout << "Assertion failed for test case 2" << endl;
        return 1;
    }

    vector<double> grades3 = {0.5};
    vector<string> expected3 = {"D-"};
    if (numerical_letter_grade(grades3) != expected3) {
        cout << "Assertion failed for test case 3" << endl;
        return 1;
    }

    vector<double> grades4 = {0.0};
    vector<string> expected4 = {"E "};
    if (numerical_letter_grade(grades4) != expected4) {
        cout << "Assertion failed for test case 4" << endl;
        return 1;
    }

    vector<double> grades5 = {1.0, 0.3, 1.5, 2.8, 3.3};
    vector<string> expected5 = {"D ", "D-", "C-", "B ", "B+"};
    if (numerical_letter_grade(grades5) != expected5) {
        cout << "Assertion failed for test case 5" << endl;
        return 1;
    }

    vector<double> grades6 = {0.0, 0.7};
    vector<string> expected6 = {"E ", "D-"};
    if (numerical_letter_grade(grades6) != expected6) {
        cout << "Assertion failed for test case 6" << endl;
        return 1;
    }

    cout << "All tests passed." << endl;
    return 0;
}
```

### 3.1.2. å£°æ

#### 3.1.2.1. åé

##### 3.1.2.1.1. åéå£°æ

```c++
int a;
double b;
```

##### 3.1.2.1.2. åéåå§å

```c++
int a = 1;
double b = 2.0;
```

##### 3.1.2.1.3. åéåå§åï¼å¸¦é»è®¤å¼ï¼

```c++
int a = 1;
double b = 2.0;
```

##### 3.1.2.1.4. åéåå§åï¼å¸¦é»è®¤å¼ï¼

```c++
int a = 1;
double b = 2.0;
```

##### 3.1.2.1.5. åéåå§åï¼å¸¦é»è®¤å¼ï¼

```c++
int a = 1;
double b = 2.0;
```

##### 3.1.2.1.6. åéåå§åï¼å¸¦é»è®¤å¼ï¼

```c++
int a = 1;
double b = 2.0;
```

##### 3.1.2.1.7. åéåå§åï¼å¸¦é»è®¤å¼ï¼

```c++
int a = 1;
double b = 2.0;
```

##### 3.1.2.1.8. åéåå§åï¼å¸¦é»è®¤å¼ï¼

```c++
int a = 1;
double b = 2.0;
```

##### 3.1.2.1.9. åéåå§åï¼å¸¦é»è®¤å¼ï¼

```c++
int a = 1;
double b = 2.0;
```

##### 3.1.2.1.10. åéåå§åï¼å¸¦é»è®¤å¼ï¼

```c++
int a = 1;
double b = 2.0;
```

##### 3.1.2.1.11. åéåå§åï¼å¸¦é»è®¤å¼ï¼

```c++
int a = 1;
double b = 2.0;
```

##### 3.1.2.1.12. åéåå§åï¼å¸¦é»è®¤å¼ï¼

```c++
int a = 1;
double b = 2.0;
```

##### 3.1.2.1.13. åéåå§åï¼å¸¦é»è®¤å¼ï¼

```c++
int a = 1;
double b = 2.0;
```

##### 3.1.2.1.14. åéåå§åï¼å¸¦é»è®¤å¼ï¼

```c++
int a = 1;
double b = 2.0;
```

##### 3.1.2.1.15. åéåå§åï¼å¸¦é»è®¤å¼ï¼

```c++
int a = 1;
double b = 2.0;
```

##### 3.1.2.1.16. åéåå§åï¼å¸¦é»è®¤å¼ï¼

```c++
int a = 1;
double b = 2.0
