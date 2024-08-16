#include <iostream>
#include <vector>

using namespace std;

bool below_threshold(const vector<int>& l, int t) {
  for (int i = 0; i < l.size(); i++) {
    if (l[i] >= t) {
      return false;
    }
  }
  return true;
}

int main() {
  vector<int> l = {1, 2, 4, 10};
  int t = 100;
  if (!below_threshold(l, t)) {
    cout << "Assertion failed: below_threshold({1, 2, 4, 10}, 100)" << endl;
    return 1;
  }

  l = {1, 20, 4, 10};
  t = 5;
  if (below_threshold(l, t)) {
    cout << "Assertion failed: not(below_threshold({1, 20, 4, 10}, 5))" << endl;
    return 1;
  }

  l = {1, 20, 4, 10};
  t = 21;
  if (!below_threshold(l, t)) {
    cout << "Assertion failed: below_threshold({1, 20, 4, 10}, 21)" << endl;
    return 1;
  }

  l = {1, 20, 4, 10};
  t = 22;
  if (!below_threshold(l, t)) {
    cout << "Assertion failed: below_threshold({1, 20, 4, 10}, 22)" << endl;
    return 1;
  }

  l = {1, 8, 4, 10};
  t = 11;
  if (!below_threshold(l, t)) {
    cout << "Assertion failed: below_threshold({1, 8, 4, 10}, 11)" << endl;
    return 1;
  }

  l = {1, 8, 4, 10};
  t = 10;
  if (below_threshold(l, t)) {
    cout << "Assertion failed: not(below_threshold({1, 8, 4, 10}, 10))" << endl;
    return 1;
  }

  return 0;
}

#include <iostream>
#include <vector>

using namespace std;

bool below_threshold(const vector<int>& l, int t) {
  for (int i = 0; i < l.size(); i++) {
    if (l[i] >= t) {
      return false;
    }
  }
  return true;
}

int main() {
  vector<int> l = {1, 2, 4, 10};
  int t = 100;
  if (!below_threshold(l, t)) {
    cout << "Assertion failed: below_threshold({1, 2, 4, 10}, 100)" << endl;
    return 1;
  }

  l = {1, 20, 4, 10};
  t = 5;
  if (below_threshold(l, t)) {
    cout << "Assertion failed: not(below_threshold({1, 20, 4, 10}, 5))" << endl;
    return 1;
  }

  l = {1, 20, 4, 10};
  t = 21;
  if (!below_threshold(l, t)) {
    cout << "Assertion failed: below_threshold({1, 20, 4, 10}, 21)" << endl;
    return 1;
  }

  l = {1, 20, 4, 10};
  t = 22;
  if (!below_threshold(l, t)) {
    cout << "Assertion failed: below_threshold({1, 20, 4, 10}, 22)" << endl;
    return 1;
  }

  l = {1, 8, 4, 10};
  t = 11;
  if (!below_threshold(l, t)) {
    cout << "Assertion failed: below_threshold({1, 8, 4, 10}, 11)" << endl;
    return 1;
  }

  l = {1, 8, 4, 10};
  t = 10;
  if (below_threshold(l, t)) {
    cout << "Assertion failed: not(below_threshold({1, 8, 4, 10}, 10))" << endl;
    return 1;
  }

  return 0;
}

#include <iostream>
#include <vector>

using namespace std;

bool below_threshold(const vector<int>& l, int t) {
  for (int i = 0; i < l.size(); i++) {
    if (l[i] >= t) {
      return false;
    }
  }
  return true;
}

int main() {
  vector<int> l = {1, 2, 4, 10};
  int t = 100;
  if (!below_threshold(l, t)) {
    cout << "Assertion failed: below_threshold({1, 2, 4, 10}, 100)" << endl;
    return 1;
  }

  l = {1, 20, 4, 10};
  t = 5;
  if (below_threshold(l, t)) {
    cout << "Assertion failed: not(below_threshold({1, 20, 4, 10}, 5))" << endl;
    return 1;
  }

  l = {1, 20, 4, 10};
  t = 21;
  if (!below_threshold(l, t)) {
    cout << "Assertion failed: below_threshold({1, 20, 4, 10}, 21)" << endl;
    return 1;
  }

  l = {1, 20, 4, 10};
  t = 22;
  if (!below_threshold(l, t)) {
    cout << "Assertion failed: below_threshold({1, 20, 4, 10}, 22)" << endl;
    return 1;
  }

  l = {1, 8, 4, 10};
  t = 11;
  if (!below_threshold(l, t)) {
    cout << "Assertion failed: below_threshold({1, 8, 4, 10}, 11)" << endl;
    return 1;
  }

  l = {1, 8, 4, 10};
  t = 10;
  if (below_threshold(l, t)) {
    cout << "Assertion failed: not(below_threshold({1, 8, 4, 10}, 10))" << endl;
    return 1;
  }

  return 0;
}

#include <iostream>
#include <vector>

using namespace std;

bool below_threshold(const vector<int>& l, int t) {
  for (int i = 0; i < l.size(); i++) {
    if (l[i] >= t) {
      return false;
    }
  }
  return true;
}

int main() {
  vector<int> l = {1, 2, 4, 10};
  int t = 100;
  if (!below_threshold(l, t)) {
    cout << "Assertion failed: below_threshold({1, 2, 4, 10}, 100)" << endl;
    return 1;
  }

  l = {1, 20, 4, 10};
  t = 5;
  if (below_threshold(l,
