#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void common(vector<int> l1, vector<int> l2, vector<int> &out) {
    vector<int> temp;
    int n = 0;
    bool found;

    for (int i = 0; i < l1.size(); i++) {
        found = false;
        for (int j = 0; j < n; j++) {
            if (temp[j] == l1[i]) {
                found = true;
                break;
            }
        }
        if (!found) {
            if (any_of(l2.begin(), l2.end(), [&](int x) { return x == l1[i]; })) {
                n++;
                temp.push_back(l1[i]);
            }
        }
    }

    if (n > 0) {
        sort(temp.begin(), temp.end());
        out = temp;
    } else {
        out.clear();
    }
}

int main() {
    vector<int> l1 = {1, 4, 3, 34, 653, 2, 5};
    vector<int> l2 = {5, 7, 1, 5, 9, 653, 121};
    vector<int> result;
    vector<int> expected = {1, 5, 653};
    common(l1, l2, result);
    if (result != expected) {
        cout << "Test case 1 failed" << endl;
        return 1;
    }

    l1 = {5, 3, 2, 8};
    l2 = {3, 2};
    expected = {2, 3};
    common(l1, l2, result);
    if (result != expected) {
        cout << "Test case 2 failed" << endl;
        return 1;
    }

    l1 = {4, 3, 2, 8};
    l2 = {3, 2, 4};
    expected = {2, 3, 4};
    common(l1, l2, result);
    if (result != expected) {
        cout << "Test case 3 failed" << endl;
        return 1;
    }

    l1 = {4, 3, 2, 8};
    l2.clear();
    expected.clear();
    common(l1, l2, result);
    if (result != expected) {
        cout << "Test case 4 failed" << endl;
        return 1;
    }

    cout << "All test cases passed" << endl;
    return 0;
}
```

### 3.2.2.3 å¾ªç¯åé

```
[Fortran]
do i = 1, 10
    print *, i
end do

[C++]
for (int i = 1; i <= 10; i++) {
    cout << i << endl;
}
```

### 3.2.2.4 å¾ªç¯æ§å¶

```
[Fortran]
do i = 1, 10
    if (i == 5) exit
    print *, i
end do

[C++]
for (int i = 1; i <= 10; i++) {
    if (i == 5) break;
    cout << i << endl;
}
```

### 3.2.2.5 å¾ªç¯åµå¥

```
[Fortran]
do i = 1, 10
    do j = 1, 10
        print *, i, j
    end do
end do

[C++]
for (int i = 1; i <= 10; i++) {
    for (int j = 1; j <= 10; j++) {
        cout << i << " " << j << endl;
    }
}
```

### 3.2.2.6 å¾ªç¯ä¸­çåæ¯

```
[Fortran]
do i = 1, 10
    if (i == 5) exit
    print *, i
end do

[C++]
for (int i = 1; i <= 10; i++) {
    if (i == 5) break;
    cout << i << endl;
}
```

### 3.2.2.7 å¾ªç¯ä¸­çå¾ªç¯

```
[Fortran]
do i = 1, 10
    do j = 1, 10
        print *, i, j
    end do
end do

[C++]
for (int i = 1; i <= 10; i++) {
    for (int j = 1; j <= 10; j++) {
        cout << i << " " << j << endl;
    }
}
```

### 3.2.2.8 å¾ªç¯ä¸­çåæ¯

```
[Fortran]
do i = 1, 10
    if (i == 5) exit
    print *, i
end do

[C++]
for (int i = 1; i <= 10; i++) {
    if (i == 5) break;
    cout << i << endl;
}
```

### 3.2.2.9 å¾ªç¯ä¸­çå¾ªç¯

```
[Fortran]
do i = 1, 10
    do j = 1, 10
        print *, i, j
    end do
end do

[C++]
for (int i = 1; i <= 10; i++) {
    for (int j = 1; j <= 10; j++) {
        cout << i << " " << j << endl;
    }
}
```

### 3.2.2.10 å¾ªç¯ä¸­çåæ¯

```
[Fortran]
do i = 1, 10
    if (i == 5) exit
    print *, i
end do

[C++]
for (int i = 1; i <= 10; i++) {
    if (i == 5) break;
    cout << i << endl;
}
```

### 3.2.2.11 å¾ªç¯ä¸­çå¾ªç¯

```
[Fortran]
do i = 1, 10
    do j = 1, 10
        print *, i, j
    end do
end do

[C++]
for (int i = 1; i <= 10; i++) {
    for (int j = 1; j <= 10; j++) {
        cout << i << " " << j << endl;
    }
}
```

### 3.2.2.12 å¾ªç¯ä¸­çåæ¯

```
[Fortran]
do i = 1, 10
    if (i == 5) exit
    print *, i
end do

[C++]
for (int i = 1; i <= 10; i++) {
    if (i == 5) break;
    cout << i << endl;
}
```

### 3.2.2.13 å¾ªç¯ä¸­çå¾ªç¯

```
[Fortran]
do i = 1, 10
    do j = 1, 10
        print *, i, j
    end do
end do

[C++]
for (int i = 1; i <= 10; i++) {
    for (int j = 1; j <= 10; j++) {
        cout << i << " " << j << endl;
    }
}
```

### 3.2.2.14 å¾ªç¯ä¸­çåæ¯

```
[Fortran]
do i = 1, 10
    if (i == 5) exit
    print *, i
end do

[C
