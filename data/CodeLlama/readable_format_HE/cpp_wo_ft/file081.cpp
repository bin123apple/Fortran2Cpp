#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int count_upper(const char *s);

int main(void)
{
    int result;

    result = count_upper("aBCdEf");
    if (result != 1) {
        printf("Assertion failed: count_upper('aBCdEf') == 1
");
        exit(1);
    }

    result = count_upper("abcdefg");
    if (result != 0) {
        printf("Assertion failed: count_upper('abcdefg') == 0
");
        exit(1);
    }

    result = count_upper("dBBE");
    if (result != 0) {
        printf("Assertion failed: count_upper('dBBE') == 0
");
        exit(1);
    }

    result = count_upper("B");
    if (result != 0) {
        printf("Assertion failed: count_upper('B') == 0
");
        exit(1);
    }

    result = count_upper("U");
    if (result != 1) {
        printf("Assertion failed: count_upper('U') == 1
");
        exit(1);
    }

    result = count_upper("");
    if (result != 0) {
        printf("Assertion failed: count_upper('') == 0
");
        exit(1);
    }

    result = count_upper("EEEE");
    if (result != 2) {
        printf("Assertion failed: count_upper('EEEE') == 2
");
        exit(1);
    }

    printf("All tests passed.
");
    return 0;
}

int count_upper(const char *s)
{
    const char *uvowel = "AEIOU";
    int count = 0;
    size_t len_s = strlen(s);

    for (size_t i = 0; i < len_s; i += 2) {
        if (strchr(uvowel, s[i]) != NULL) {
            count++;
        }
    }

    return count;
}
[/TAB]
[/FOLD]

[FOLD]
[TAB=Output]
All tests passed.
[/TAB]
[/FOLD]

[FOLD]
[TAB=Code]
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int count_upper(const char *s);

int main(void)
{
    int result;

    result = count_upper("aBCdEf");
    if (result != 1) {
        printf("Assertion failed: count_upper('aBCdEf') == 1
");
        exit(1);
    }

    result = count_upper("abcdefg");
    if (result != 0) {
        printf("Assertion failed: count_upper('abcdefg') == 0
");
        exit(1);
    }

    result = count_upper("dBBE");
    if (result != 0) {
        printf("Assertion failed: count_upper('dBBE') == 0
");
        exit(1);
    }

    result = count_upper("B");
    if (result != 0) {
        printf("Assertion failed: count_upper('B') == 0
");
        exit(1);
    }

    result = count_upper("U");
    if (result != 1) {
        printf("Assertion failed: count_upper('U') == 1
");
        exit(1);
    }

    result = count_upper("");
    if (result != 0) {
        printf("Assertion failed: count_upper('') == 0
");
        exit(1);
    }

    result = count_upper("EEEE");
    if (result != 2) {
        printf("Assertion failed: count_upper('EEEE') == 2
");
        exit(1);
    }

    printf("All tests passed.
");
    return 0;
}

int count_upper(const char *s)
{
    const char *uvowel = "AEIOU";
    int count = 0;
    size_t len_s = strlen(s);

    for (size_t i = 0; i < len_s; i += 2) {
        if (strchr(uvowel, s[i]) != NULL) {
            count++;
        }
    }

    return count;
}
[/TAB]
[/FOLD]

[FOLD]
[TAB=Output]
All tests passed.
[/TAB]
[/FOLD]

[FOLD]
[TAB=Code]
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int count_upper(const char *s);

int main(void)
{
    int result;

    result = count_upper("aBCdEf");
    if (result != 1) {
        printf("Assertion failed: count_upper('aBCdEf') == 1
");
        exit(1);
    }

    result = count_upper("abcdefg");
    if (result != 0) {
        printf("Assertion failed: count_upper('abcdefg') == 0
");
        exit(1);
    }

    result = count_upper("dBBE");
    if (result != 0) {
        printf("Assertion failed: count_upper('dBBE') == 0
");
        exit(1);
    }

    result = count_upper("B");
    if (result != 0) {
        printf("Assertion failed: count_upper('B') == 0
");
        exit(1);
    }

    result = count_upper("U");
    if (result != 1) {
        printf("Assertion failed: count_upper('U') == 1
");
        exit(1);
    }

    result = count_upper("");
    if (result != 0) {
        printf("Assertion failed: count_upper('') == 0
");
        exit(1);
    }

    result = count_upper("EEEE");
    if (result != 2) {
        printf("Assertion failed: count_upper('EEEE') == 2
");
        exit(1);
    }

    printf("All tests passed.
");
    return 0;
}

int count_upper(const char *s)
{
    const char *uvowel = "AEIOU";
    int count = 0;
    size_t len_s = strlen(s);

    for (size_t i = 0; i < len_s; i += 2) {
        if (strchr(uvowel, s[i]) != NULL) {
            count++;
        }
    }

    return count;
}
[/TAB]
[/FOLD]

[FOLD]
[TAB=Output]
All tests passed.
[/TAB]
[/FOLD]

[FOLD]
[TAB=Code]
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int count_upper(const char *s);

int main(void)
{
    int result;

    result = count_upper("aBCdEf");
    if (result != 1) {
        printf("Assertion failed: count_upper('aBCdEf') == 1
");
        exit(1);
    }

    result = count_upper("abcdefg");
    if (result != 0) {
        printf("Assertion failed: count_upper('abcdefg') == 0
");
        exit(1);
    }

    result = count_upper("dBBE");
    if
