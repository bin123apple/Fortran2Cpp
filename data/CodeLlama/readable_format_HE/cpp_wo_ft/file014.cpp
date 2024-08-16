#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cassert>

using namespace std;

vector<int> parse_music(const string& music_string) {
    vector<int> result;
    string current;
    stringstream ss(music_string);
    string token;

    while (ss >> token) {
        if (token == "o") {
            result.push_back(4);
        } else if (token == "o|") {
            result.push_back(2);
        } else if (token == ".|") {
            result.push_back(1);
        }
    }
    return result;
}

int main() {
    assert(parse_music("") == vector<int>());
    assert(parse_music("o o o o") == vector<int>{4, 4, 4, 4});
    assert(parse_music(".| .| .| .|") == vector<int>{1, 1, 1, 1});
    assert(parse_music("o| o| .| .| o o o o") == vector<int>{2, 2, 1, 1, 4, 4, 4, 4});
    assert(parse_music("o| .| o| .| o o| o o|") == vector<int>{2, 1, 2, 1, 4, 2, 4, 2});
    return 0;
}
```

### 2.3.2. å¾ªç¯

```
[Fortran]
program loop_test
    implicit none
    integer :: i

    do i = 1, 10
        print *, i
    end do
end program loop_test

[C++]
#include <iostream>

int main() {
    for (int i = 1; i <= 10; i++) {
        std::cout << i << std::endl;
    }
    return 0;
}
```

### 2.3.3. æ¡ä»¶è¯­å¥

```
[Fortran]
program if_test
    implicit none
    integer :: i

    i = 10
    if (i == 10) then
        print *, "i is 10"
    else if (i == 20) then
        print *, "i is 20"
    else
        print *, "i is neither 10 nor 20"
    end if
end program if_test

[C++]
#include <iostream>

int main() {
    int i = 10;
    if (i == 10) {
        std::cout << "i is 10" << std::endl;
    } else if (i == 20) {
        std::cout << "i is 20" << std::endl;
    } else {
        std::cout << "i is neither 10 nor 20" << std::endl;
    }
    return 0;
}
```

### 2.3.4. å½æ°

```
[Fortran]
program function_test
    implicit none
    integer :: i

    i = 10
    print *, "i is ", i
    i = i + 1
    print *, "i is ", i
end program function_test

[C++]
#include <iostream>

int main() {
    int i = 10;
    std::cout << "i is " << i << std::endl;
    i = i + 1;
    std::cout << "i is " << i << std::endl;
    return 0;
}
```

### 2.3.5. æ°ç»

```
[Fortran]
program array_test
    implicit none
    integer, dimension(10) :: a
    integer :: i

    do i = 1, 10
        a(i) = i
    end do
    do i = 1, 10
        print *, a(i)
    end do
end program array_test

[C++]
#include <iostream>

int main() {
    int a[10];
    for (int i = 0; i < 10; i++) {
        a[i] = i;
    }
    for (int i = 0; i < 10; i++) {
        std::cout << a[i] << std::endl;
    }
    return 0;
}
```

### 2.3.6. å­ç¬¦ä¸²

```
[Fortran]
program string_test
    implicit none
    character(len=100) :: s

    s = "Hello, world!"
    print *, s
end program string_test

[C++]
#include <iostream>

int main() {
    std::string s = "Hello, world!";
    std::cout << s << std::endl;
    return 0;
}
```

### 2.3.7. ç»æä½

```
[Fortran]
program struct_test
    implicit none
    type point
        real :: x
        real :: y
    end type point
    type(point) :: p

    p%x = 10
    p%y = 20
    print *, p%x, p%y
end program struct_test

[C++]
#include <iostream>

struct Point {
    float x;
    float y;
};

int main() {
    Point p;
    p.x = 10;
    p.y = 20;
    std::cout << p.x << " " << p.y << std::endl;
    return 0;
}
```

### 2.3.8. æä¸¾

```
[Fortran]
program enum_test
    implicit none
    enum, bind(c)
        enumerator :: red, green, blue
    end enum
    integer(c_int) :: color

    color = red
    print *, color
end program enum_test

[C++]
#include <iostream>

enum Color {
    RED,
    GREEN,
    BLUE
};

int main() {
    Color color = RED;
    std::cout << color << std::endl;
    return 0;
}
```

### 2.3.9. ç±»

```
[Fortran]
program class_test
    implicit none
    type point
        real :: x
        real :: y
    contains
        procedure :: distance
    end type point
    type(point) :: p1, p2
    real :: distance

    p1%x = 10
    p1%y = 20
    p2%x = 10
    p2%y = 20
    distance = p1%distance(p2)
    print *, distance
end program class_test

[C++]
#include <iostream>

struct Point {
    float x;
    float y;
    float distance(Point p) {
        return sqrt((x - p.x) * (x - p.x) + (y - p.y) * (y - p.y));
    }
};

int main() {
    Point p1, p2;
    p1.x = 10;
    p1.y = 20;
    p2.x = 10;
    p2.y = 20;
    std::cout << p1.distance(p2) << std::endl;
    return 0;
}
```

### 2.3.10. æ¨¡å

```
[Fortran]
module math_module
    implicit none
    contains
        function add(a, b) result(c)
            integer, intent(in) :: a, b
            integer :: c
            c = a + b
        end function add
end module math_module

program module_test
    use math_module
    implicit none
    integer :: a, b, c

    a = 10
    b = 20
    c = add(a, b)
    print *, c
end program module_test

[C++]
#include <
