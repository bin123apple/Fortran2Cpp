#include <iostream>
#include <vector>

using namespace std;

bool below_zero(vector<int> operations) {
    int num = 0;
    for (int i = 0; i < operations.size(); i++) {
        num += operations[i];
        if (num < 0) {
            return true;
        }
    }
    return false;
}

int main() {
    vector<int> operations;
    bool result;

    // Test cases
    operations = {};
    result = below_zero(operations);
    if (result != false) {
        cout << "Test case 1 failed" << endl;
        return 1;
    }

    operations = {1, 2, -3, 1, 2, -3};
    result = below_zero(operations);
    if (result != false) {
        cout << "Test case 2 failed" << endl;
        return 1;
    }

    operations = {1, 2, -4, 5, 6};
    result = below_zero(operations);
    if (result != true) {
        cout << "Test case 3 failed" << endl;
        return 1;
    }

    operations = {1, -1, 2, -2, 5, -5, 4, -4};
    result = below_zero(operations);
    if (result != false) {
        cout << "Test case 4 failed" << endl;
        return 1;
    }

    operations = {1, -1, 2, -2, 5, -5, 4, -5};
    result = below_zero(operations);
    if (result != true) {
        cout << "Test case 5 failed" << endl;
        return 1;
    }

    operations = {1, -2, 2, -2, 5, -5, 4, -4};
    result = below_zero(operations);
    if (result != true) {
        cout << "Test case 6 failed" << endl;
        return 1;
    }

    cout << "All test cases passed" << endl;
    return 0;
}
```

### 2.3.2.2 ç»ä¹ ï¼æ¾åºæå¤§å­æ°ç»å

#### 2.3.2.2.1 é¢ç®

ç»å®ä¸ä¸ªæ´æ°æ°ç»ï¼æ¾åºä¸ä¸ªå­æ°ç»ï¼ä½¿å¾å­æ°ç»ä¸­åç´ çåæå¤§ã

#### 2.3.2.2.2 è§£ç­

```c++
#include <iostream>
#include <vector>

using namespace std;

int max_subarray_sum(vector<int> numbers) {
    int max_sum = 0;
    int sum = 0;
    for (int i = 0; i < numbers.size(); i++) {
        sum += numbers[i];
        if (sum > max_sum) {
            max_sum = sum;
        }
        if (sum < 0) {
            sum = 0;
        }
    }
    return max_sum;
}

int main() {
    vector<int> numbers = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << max_subarray_sum(numbers) << endl;
    return 0;
}
```

### 2.3.2.3 ç»ä¹ ï¼æ¾åºæå¤§å­æ°ç»ä¹ç§¯

#### 2.3.2.3.1 é¢ç®

ç»å®ä¸ä¸ªæ´æ°æ°ç»ï¼æ¾åºä¸ä¸ªå­æ°ç»ï¼ä½¿å¾å­æ°ç»ä¸­åç´ çä¹ç§¯æå¤§ã

#### 2.3.2.3.2 è§£ç­

```c++
#include <iostream>
#include <vector>

using namespace std;

int max_subarray_product(vector<int> numbers) {
    int max_product = 0;
    int product = 0;
    for (int i = 0; i < numbers.size(); i++) {
        product *= numbers[i];
        if (product > max_product) {
            max_product = product;
        }
        if (product == 0) {
            product = 1;
        }
    }
    return max_product;
}

int main() {
    vector<int> numbers = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << max_subarray_product(numbers) << endl;
    return 0;
}
```

### 2.3.2.4 ç»ä¹ ï¼æ¾åºæå¤§å­æ°ç»åçåºé´

#### 2.3.2.4.1 é¢ç®

ç»å®ä¸ä¸ªæ´æ°æ°ç»ï¼æ¾åºä¸ä¸ªå­æ°ç»ï¼ä½¿å¾å­æ°ç»ä¸­åç´ çåæå¤§ã

#### 2.3.2.4.2 è§£ç­

```c++
#include <iostream>
#include <vector>

using namespace std;

vector<int> max_subarray_sum_range(vector<int> numbers) {
    vector<int> range;
    int max_sum = 0;
    int sum = 0;
    int start = 0;
    int end = 0;
    for (int i = 0; i < numbers.size(); i++) {
        sum += numbers[i];
        if (sum > max_sum) {
            max_sum = sum;
            start = end + 1;
            end = i;
        }
        if (sum < 0) {
            sum = 0;
            start = i + 1;
        }
    }
    range.push_back(start);
    range.push_back(end);
    return range;
}

int main() {
    vector<int> numbers = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    vector<int> range = max_subarray_sum_range(numbers);
    cout << range[0] << " " << range[1] << endl;
    return 0;
}
```

### 2.3.2.5 ç»ä¹ ï¼æ¾åºæå¤§å­æ°ç»ä¹ç§¯çåºé´

#### 2.3.2.5.1 é¢ç®

ç»å®ä¸ä¸ªæ´æ°æ°ç»ï¼æ¾åºä¸ä¸ªå­æ°ç»ï¼ä½¿å¾å­æ°ç»ä¸­åç´ çä¹ç§¯æå¤§ã

#### 2.3.2.5.2 è§£ç­

```c++
#include <iostream>
#include <vector>

using namespace std;

vector<int> max_subarray_product_range(vector<int> numbers) {
    vector<int> range;
    int max_product = 0;
    int product = 0;
    int start = 0;
    int end = 0;
    for (int i = 0; i < numbers.size(); i++) {
        product *= numbers[i];
        if (product > max_product) {
            max_product = product;
            start = end + 1;
            end = i;
        }
        if (product == 0) {
            product = 1;
            start = i + 1;
        }
    }
    range.push_back(start);
    range.push_back(end);
    return range;
}

int main() {
    vector<int> numbers = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    vector<int> range = max_subarray_product_range(numbers);
    cout << range[0] << " " << range[1] << endl;
    return 0;
}
```

## 2.3.3 æ 

### 2.3.3.1 æ çæ½è±¡æ°æ®ç±»å

#### 2.3.3.1.1 æ çå®ä¹

æ æ¯ä¸ç§ç¹
