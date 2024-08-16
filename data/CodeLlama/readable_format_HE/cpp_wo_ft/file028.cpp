#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void sort_third(vector<int> &l) {
    vector<int> third;
    vector<int> out;
    int i, n, temp;

    n = l.size();
    third.resize((n + 2) / 3);
    out.resize(n);

    // Extract every third element
    for (i = 0; i < third.size(); i++) {
        third[i] = l[i * 3];
    }

    // Sort the third array
    sort(third.begin(), third.end());

    // Reconstruct the output array
    for (i = 0; i < n; i++) {
        if (i % 3 == 0) {
            out[i] = third[i / 3];
        } else {
            out[i] = l[i];
        }
    }

    l = out;
}

int main() {
    vector<int> l;
    vector<int> sorted_l;
    int i;

    l = {1, 2, 3};
    sort_third(l);
    sorted_l = {1, 2, 3};
    if (l != sorted_l) {
        cout << "Assertion failed" << endl;
        return 1;
    }

    l = {5, 3, -5, 2, -3, 3, 9, 0, 123, 1, -10};
    sort_third(l);
    sorted_l = {5, 3, -5, 2, -3, 3, 9, 0, 123, 1, -10};
    if (l != sorted_l) {
        cout << "Assertion failed" << endl;
        return 1;
    }

    l = {5, 8, -12, 4, 23, 2, 3, 11, 12, -10};
    sort_third(l);
    sorted_l = {5, 8, -12, 4, 23, 2, 3, 11, 12, -10};
    if (l != sorted_l) {
        cout << "Assertion failed" << endl;
        return 1;
    }

    l = {5, 6, 3, 4, 8, 9, 2};
    sort_third(l);
    sorted_l = {2, 6, 3, 4, 8, 9, 5};
    if (l != sorted_l) {
        cout << "Assertion failed" << endl;
        return 1;
    }

    l = {5, 8, 3, 4, 6, 9, 2};
    sort_third(l);
    sorted_l = {2, 8, 3, 4, 6, 9, 5};
    if (l != sorted_l) {
        cout << "Assertion failed" << endl;
        return 1;
    }

    l = {5, 6, 9, 4, 8, 3, 2};
    sort_third(l);
    sorted_l = {2, 6, 9, 4, 8, 3, 5};
    if (l != sorted_l) {
        cout << "Assertion failed" << endl;
        return 1;
    }

    l = {5, 6, 3, 4, 8, 9, 2, 1};
    sort_third(l);
    sorted_l = {2, 6, 3, 4, 8, 9, 5, 1};
    if (l != sorted_l) {
        cout << "Assertion failed" << endl;
        return 1;
    }

    return 0;
}
```

### 1.3.1.1. å¾ªç¯

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

### 1.3.1.2. æ¡ä»¶è¯­å¥

```
[Fortran]
if (i == 1) then
    print *, "i is 1"
else if (i == 2) then
    print *, "i is 2"
else
    print *, "i is neither 1 nor 2"
end if

[C++]
if (i == 1) {
    cout << "i is 1" << endl;
} else if (i == 2) {
    cout << "i is 2" << endl;
} else {
    cout << "i is neither 1 nor 2" << endl;
}
```

### 1.3.1.3. å½æ°

```
[Fortran]
function sort_third(l) result(out)
    implicit none
    integer, intent(in) :: l(:)
    integer, allocatable :: third(:), out(:)
    integer :: i, n, temp

    n = size(l)
    allocate(third((n + 2) / 3))
    allocate(out(n))

    ! Extract every third element
    do i = 1, size(third)
        third(i) = l((i - 1) * 3 + 1)
    end do

    ! Sort the third array
    call sort_array(third)

    ! Reconstruct the output array
    do i = 1, n
        if (mod(i - 1, 3) == 0) then
            out(i) = third((i - 1) / 3 + 1)
        else
            out(i) = l(i)
        end if
    end do
end function sort_third

[C++]
vector<int> sort_third(vector<int> &l) {
    vector<int> third;
    vector<int> out;
    int i, n, temp;

    n = l.size();
    third.resize((n + 2) / 3);
    out.resize(n);

    // Extract every third element
    for (i = 0; i < third.size(); i++) {
        third[i] = l[i * 3];
    }

    // Sort the third array
    sort(third.begin(), third.end());

    // Reconstruct the output array
    for (i = 0; i < n; i++) {
        if (i % 3 == 0) {
            out[i] = third[i / 3];
        } else {
            out[i] = l[i];
        }
    }

    return out;
}
```

### 1.3.1.4. å­ç¨åº

```
[Fortran]
subroutine sort_array(arr)
    implicit none
    integer, intent(inout) :: arr(:)
    integer :: i, j, temp

    do i = 1, size(arr) - 1
        do j = i + 1, size(arr)
            if (arr(i) > arr(j)) then
                temp = arr(i)
                arr(i) = arr(j)
                arr(j) = temp
            end if
        end do
    end do
end subroutine sort_array

[C++]
void sort_array(vector<int> &arr) {
    int i, j, temp;

    for (i = 0; i < arr.size() - 1; i++) {
        for (j = i + 1; j < arr.size(); j++) {
            if (arr[i] > arr[j]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}
```

### 1.3.1.5. æ°ç»

```
[Fortran]
integer, allocatable :: l(:), sorted_l(:)
integer :: i

[C++]
vector<int
