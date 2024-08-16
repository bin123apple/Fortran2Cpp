#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool issame(vector<string> a, vector<string> b) {
    if (a.size() != b.size()) {
        return false;
    }

    for (int i = 0; i < a.size(); i++) {
        if (a[i] != b[i]) {
            return false;
        }
    }

    return true;
}

vector<string> total_match(vector<string> a, vector<string> b) {
    vector<string> res;

    if (a.size() > b.size()) {
        res = b;
    } else {
        res = a;
    }

    return res;
}

int main() {
    vector<string> lst1 = {"hi", "admin"};
    vector<string> lst2 = {"hi", "hi", "admin", "project"};
    vector<string> result = {"hi", "admin"};
    vector<string> empty;

    assert(issame(total_match(lst1, lst2), result));

    lst1 = {"hi", "admin"};
    lst2 = {"hi", "hi", "admin", "project"};
    result = {"hi", "admin"};
    assert(issame(total_match(lst1, lst2), result));

    lst1 = {"4"};
    lst2 = {"1", "2", "3", "4", "5"};
    result = {"4"};
    assert(issame(total_match(lst1, lst2), result));

    lst1 = {"hi", "admin"};
    lst2 = {"hI", "Hi"};
    result = {"hI", "Hi"};
    assert(issame(total_match(lst1, lst2), result));

    lst1 = {"hi", "admin"};
    lst2 = {"hI", "hi", "hi"};
    result = {"hI", "hi", "hi"};
    assert(issame(total_match(lst1, lst2), result));

    lst1 = {"hi", "admin"};
    lst2 = {"hI", "hi", "hii"};
    result = {"hi", "admin"};
    assert(issame(total_match(lst1, lst2), result));

    lst1 = {};
    lst2 = {"this"};
    result = {};
    assert(issame(total_match(lst1, lst2), result));

    lst1 = {"this"};
    lst2 = {};
    result = {};
    assert(issame(total_match(lst1, lst2), result));

    return 0;
}

[C++]
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool issame(vector<string> a, vector<string> b) {
    if (a.size() != b.size()) {
        return false;
    }

    for (int i = 0; i < a.size(); i++) {
        if (a[i] != b[i]) {
            return false;
        }
    }

    return true;
}

vector<string> total_match(vector<string> a, vector<string> b) {
    vector<string> res;

    if (a.size() > b.size()) {
        res = b;
    } else {
        res = a;
    }

    return res;
}

int main() {
    vector<string> lst1 = {"hi", "admin"};
    vector<string> lst2 = {"hi", "hi", "admin", "project"};
    vector<string> result = {"hi", "admin"};
    vector<string> empty;

    assert(issame(total_match(lst1, lst2), result));

    lst1 = {"hi", "admin"};
    lst2 = {"hi", "hi", "admin", "project"};
    result = {"hi", "admin"};
    assert(issame(total_match(lst1, lst2), result));

    lst1 = {"4"};
    lst2 = {"1", "2", "3", "4", "5"};
    result = {"4"};
    assert(issame(total_match(lst1, lst2), result));

    lst1 = {"hi", "admin"};
    lst2 = {"hI", "Hi"};
    result = {"hI", "Hi"};
    assert(issame(total_match(lst1, lst2), result));

    lst1 = {"hi", "admin"};
    lst2 = {"hI", "hi", "hi"};
    result = {"hI", "hi", "hi"};
    assert(issame(total_match(lst1, lst2), result));

    lst1 = {"hi", "admin"};
    lst2 = {"hI", "hi", "hii"};
    result = {"hi", "admin"};
    assert(issame(total_match(lst1, lst2), result));

    lst1 = {};
    lst2 = {"this"};
    result = {};
    assert(issame(total_match(lst1, lst2), result));

    lst1 = {"this"};
    lst2 = {};
    result = {};
    assert(issame(total_match(lst1, lst2), result));

    return 0;
}

[C++]
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool issame(vector<string> a, vector<string> b) {
    if (a.size() != b.size()) {
        return false;
    }

    for (int i = 0; i < a.size(); i++) {
        if (a[i] != b[i]) {
            return false;
        }
    }

    return true;
}

vector<string> total_match(vector<string> a, vector<string> b) {
    vector<string> res;

    if (a.size() > b.size()) {
        res = b;
    } else {
        res = a;
    }

    return res;
}

int main() {
    vector<string> lst1 = {"hi", "admin"};
    vector<string> lst2 = {"hi", "hi", "admin", "project"};
    vector<string> result = {"hi", "admin"};
    vector<string> empty;

    assert(issame(total_match(lst1, lst2), result));

    lst1 = {"hi", "admin"};
    lst2 = {"hi", "hi", "admin", "project"};
    result = {"hi", "admin"};
    assert(issame(total_match(lst1, lst2), result));

    lst1 = {"4"};
    lst2 = {"1", "2", "3", "4", "5"};
    result = {"4"};
    assert(issame(total_match(lst1, lst2), result));

    lst1 = {"hi", "admin"};
    lst2 = {"hI", "Hi"};
    result = {"hI", "Hi"};
    assert(issame(total_match(lst1, lst2), result));

    lst1 = {"hi", "admin"};
    lst2 = {"hI", "hi", "hi"};
    result = {"hI", "hi", "hi"};
    assert(issame(total_match(lst1, lst2), result));

    lst1 = {"hi", "admin"};
    lst2 = {"hI", "hi", "hii"};
    result = {"hi", "admin"};
    assert(issame(total_match(lst1, lst2), result));

    lst1 = {};
    lst2 = {"this"};
    result = {};
    assert(issame(total_match(lst1, lst2), result));

    lst1 = {"this"};
    lst2 = {};
    result = {};
    assert(issame(total_match(lst1, lst2), result));

    return 0;
}

[C++]
#include <iostream
