#include <cmath>
#include <cstdlib>
#include <iostream>
#include <vector>

// Define the poly function
double poly(const std::vector<double>& xs, int n, double x) {
    double sum = 0.0;
    for (int i = 1; i <= n; ++i) {
        sum += xs[i - 1] * pow(x, i - 1);
    }
    return sum;
}

// Define the find_zero function
double find_zero(const std::vector<double>& xs, int n) {
    double ans = 0.0;
    double value = poly(xs, n, ans);
    while (std::abs(value) > 1e-6) {
        double driv = 0.0;
        for (int i = 2; i <= n; ++i) {
            driv += xs[i - 1] * (i - 1) * pow(ans, i - 2);
        }
        ans -= value / driv;
        value = poly(xs, n, ans);
    }
    return ans;
}

int main() {
    srand(time(NULL));
    for (int i = 0; i < 100; ++i) {
        int ncoeff = 2 * (1 + rand() % 4);
        std::vector<double> coeffs(ncoeff);
        for (int j = 0; j < ncoeff; ++j) {
            coeffs[j] = -10 + rand() % 21;
            if (coeffs[j] == 0) coeffs[j] = 1;
        }

        double solution = find_zero(coeffs, ncoeff);
        if (std::abs(poly(coeffs, ncoeff, solution)) >= 1e-3) {
            std::cout << "Assertion failed: abs(poly(coeffs, solution)) < 1e-3"
                      << std::endl;
            return 1;
        }
    }
    return 0;
}
```

### 1.2.2. å¾ªç¯å±å¼

å¾ªç¯å±å¼æ¯æå°å¾ªç¯ä½ä¸­çä»£ç å¤å¶å°å¾ªç¯ä½å¤ï¼ç¶åå°å¾ªç¯åéçå¼æ¿æ¢ä¸ºå¾ªç¯åéçåå§å¼ãæ«å°¾å¼åæ­¥é¿ï¼ä»èæ¶é¤å¾ªç¯ã

å¾ªç¯å±å¼çä¼ç¹æ¯å¯ä»¥æ¶é¤å¾ªç¯ï¼ä»èæé«ç¨åºçæ§è¡æçã

å¾ªç¯å±å¼çç¼ºç¹æ¯ç¨åºåå¾å¤æï¼å¢å äºä»£ç éã

```
[C]
void sum_array(int n, double *a, double *b) {
    int i;
    for (i = 0; i < n; ++i) {
        b[i] = a[i] + b[i];
    }
}

[C++]
void sum_array(int n, double *a, double *b) {
    for (int i = 0; i < n; ++i) {
        b[i] = a[i] + b[i];
    }
}
```

### 1.2.3. å¾ªç¯å±å¼çæ¿ä»£æ¹æ³

å¾ªç¯å±å¼çæ¿ä»£æ¹æ³æ¯ä½¿ç¨ç¼è¯å¨æä¾çå¾ªç¯å±å¼åè½ã

```
[C]
void sum_array(int n, double *a, double *b) {
    int i;
    for (i = 0; i < n; ++i) {
        b[i] = a[i] + b[i];
    }
}

[C++]
void sum_array(int n, double *a, double *b) {
    for (int i = 0; i < n; ++i) {
        b[i] = a[i] + b[i];
    }
}
```

### 1.2.4. å¾ªç¯å±å¼çæ¿ä»£æ¹æ³

å¾ªç¯å±å¼çæ¿ä»£æ¹æ³æ¯ä½¿ç¨ç¼è¯å¨æä¾çå¾ªç¯å±å¼åè½ã

```
[C]
void sum_array(int n, double *a, double *b) {
    int i;
    for (i = 0; i < n; ++i) {
        b[i] = a[i] + b[i];
    }
}

[C++]
void sum_array(int n, double *a, double *b) {
    for (int i = 0; i < n; ++i) {
        b[i] = a[i] + b[i];
    }
}
```

### 1.2.5. å¾ªç¯å±å¼çæ¿ä»£æ¹æ³

å¾ªç¯å±å¼çæ¿ä»£æ¹æ³æ¯ä½¿ç¨ç¼è¯å¨æä¾çå¾ªç¯å±å¼åè½ã

```
[C]
void sum_array(int n, double *a, double *b) {
    int i;
    for (i = 0; i < n; ++i) {
        b[i] = a[i] + b[i];
    }
}

[C++]
void sum_array(int n, double *a, double *b) {
    for (int i = 0; i < n; ++i) {
        b[i] = a[i] + b[i];
    }
}
```

### 1.2.6. å¾ªç¯å±å¼çæ¿ä»£æ¹æ³

å¾ªç¯å±å¼çæ¿ä»£æ¹æ³æ¯ä½¿ç¨ç¼è¯å¨æä¾çå¾ªç¯å±å¼åè½ã

```
[C]
void sum_array(int n, double *a, double *b) {
    int i;
    for (i = 0; i < n; ++i) {
        b[i] = a[i] + b[i];
    }
}

[C++]
void sum_array(int n, double *a, double *b) {
    for (int i = 0; i < n; ++i) {
        b[i] = a[i] + b[i];
    }
}
```

### 1.2.7. å¾ªç¯å±å¼çæ¿ä»£æ¹æ³

å¾ªç¯å±å¼çæ¿ä»£æ¹æ³æ¯ä½¿ç¨ç¼è¯å¨æä¾çå¾ªç¯å±å¼åè½ã

```
[C]
void sum_array(int n, double *a, double *b) {
    int i;
    for (i = 0; i < n; ++i) {
        b[i] = a[i] + b[i];
    }
}

[C++]
void sum_array(int n, double *a, double *b) {
    for (int i = 0; i < n; ++i) {
        b[i] = a[i] + b[i];
    }
}
```

### 1.2.8. å¾ªç¯å±å¼çæ¿ä»£æ¹æ³

å¾ªç¯å±å¼çæ¿ä»£æ¹æ³æ¯ä½¿ç¨ç¼è¯å¨æä¾çå¾ªç¯å±å¼åè½ã

```
[C]
void sum_array(int n, double *a, double *b) {
    int i;
    for (i = 0; i < n; ++i) {
        b[i] = a[i] + b[i];
    }
}

[C++]
void sum_array(int n, double *a, double *b) {
    for (int i = 0; i < n; ++i) {
        b[i] = a[i] + b[i];
    }
}
```

###
