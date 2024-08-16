#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<double> find_closest_elements(vector<double> numbers) {
    vector<double> out(2);
    double min_diff = numeric_limits<double>::max();

    for (int i = 0; i < numbers.size(); i++) {
        for (int j = i + 1; j < numbers.size(); j++) {
            if (abs(numbers[i] - numbers[j]) < min_diff) {
                out[0] = numbers[i];
                out[1] = numbers[j];
                min_diff = abs(numbers[i] - numbers[j]);
            }
        }
    }

    if (out[0] > out[1]) {
        swap(out[0], out[1]);
    }

    return out;
}

bool issame(vector<double> a, vector<double> b) {
    if (a.size() != b.size()) {
        return false;
    }

    for (int i = 0; i < a.size(); i++) {
        if (abs(a[i] - b[i]) > 1e-4) {
            return false;
        }
    }

    return true;
}

int main() {
    vector<double> test1 = {1.0, 2.0, 3.9, 4.0, 5.0, 2.2};
    vector<double> test2 = {1.0, 2.0, 5.9, 4.0, 5.0};
    vector<double> test3 = {1.0, 2.0, 3.0, 4.0, 5.0, 2.2};
    vector<double> test4 = {1.0, 2.0, 3.0, 4.0, 5.0, 2.0};
    vector<double> test5 = {1.1, 2.2, 3.1, 4.1, 5.1};

    vector<double> result = find_closest_elements(test1);
    if (!issame(result, {3.9, 4.0})) {
        cout << "Assertion failed for test1" << endl;
        return 1;
    }

    result = find_closest_elements(test2);
    if (!issame(result, {5.0, 5.9})) {
        cout << "Assertion failed for test2" << endl;
        return 1;
    }

    result = find_closest_elements(test3);
    if (!issame(result, {2.0, 2.2})) {
        cout << "Assertion failed for test3" << endl;
        return 1;
    }

    result = find_closest_elements(test4);
    if (!issame(result, {2.0, 2.0})) {
        cout << "Assertion failed for test4" << endl;
        return 1;
    }

    result = find_closest_elements(test5);
    if (!issame(result, {2.2, 3.1})) {
        cout << "Assertion failed for test5" << endl;
        return 1;
    }

    cout << "All tests passed" << endl;
    return 0;
}
```

### 3.1.3. ë°°ì´ ì´ê¸°í

```
[Fortran]
program main
    implicit none
    integer, dimension(3) :: a = [1, 2, 3]
    integer, dimension(3) :: b = [1, 2, 3]
    integer, dimension(3) :: c = [1, 2, 3]
    integer, dimension(3) :: d = [1, 2, 3]
    integer, dimension(3) :: e = [1, 2, 3]
    integer, dimension(3) :: f = [1, 2, 3]
    integer, dimension(3) :: g = [1, 2, 3]
    integer, dimension(3) :: h = [1, 2, 3]
    integer, dimension(3) :: i = [1, 2, 3]
    integer, dimension(3) :: j = [1, 2, 3]
    integer, dimension(3) :: k = [1, 2, 3]
    integer, dimension(3) :: l = [1, 2, 3]
    integer, dimension(3) :: m = [1, 2, 3]
    integer, dimension(3) :: n = [1, 2, 3]
    integer, dimension(3) :: o = [1, 2, 3]
    integer, dimension(3) :: p = [1, 2, 3]
    integer, dimension(3) :: q = [1, 2, 3]
    integer, dimension(3) :: r = [1, 2, 3]
    integer, dimension(3) :: s = [1, 2, 3]
    integer, dimension(3) :: t = [1, 2, 3]
    integer, dimension(3) :: u = [1, 2, 3]
    integer, dimension(3) :: v = [1, 2, 3]
    integer, dimension(3) :: w = [1, 2, 3]
    integer, dimension(3) :: x = [1, 2, 3]
    integer, dimension(3) :: y = [1, 2, 3]
    integer, dimension(3) :: z = [1, 2, 3]
end program main
```

```
[C++]
#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> a = {1, 2, 3};
    vector<int> b = {1, 2, 3};
    vector<int> c = {1, 2, 3};
    vector<int> d = {1, 2, 3};
    vector<int> e = {1, 2, 3};
    vector<int> f = {1, 2, 3};
    vector<int> g = {1, 2, 3};
    vector<int> h = {1, 2, 3};
    vector<int> i = {1, 2, 3};
    vector<int> j = {1, 2, 3};
    vector<int> k = {1, 2, 3};
    vector<int> l = {1, 2, 3};
    vector<int> m = {1, 2, 3};
    vector<int> n = {1, 2, 3};
    vector<int> o = {1, 2, 3};
    vector<int> p = {1, 2, 3};
    vector<int> q = {1, 2, 3};
    vector<int> r = {1, 2, 3};
    vector<int> s = {1, 2, 3};
    vector<int> t = {1, 2, 3};
    vector<int> u = {1, 2, 3};
    vector<int> v = {1, 2, 3};
    vector<int> w = {1, 2, 3};
    vector<int> x = {1, 2, 3};
    vector<int> y = {1, 2, 3};
    vector<int> z = {1, 2, 3};
}
```

### 3.1.4. ë°°ì´ ìì±

```
[Fortran]
program main
    implicit none
    integer, dimension(3) :: a
    integer, dimension(3) :: b
    integer, dimension(3) :: c
    integer, dimension(3) :: d
    integer, dimension(3) :: e
    integer, dimension(3) :: f
    integer, dimension(3) :: g
    integer, dimension(3) :: h
    integer, dimension(3) :: i
    integer, dimension(3) :: j
    integer, dimension(3) :: k
    integer, dimension(3) :: l
    integer, dimension
