#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>

using namespace std;

bool valid_date(const string &date)
{
    if (date.length() != 10)
        return false;

    for (int i = 0; i < 10; i++)
    {
        if (i == 3 || i == 6)
        {
            if (date[i] != '-')
                return false;
        }
        else
        {
            if (date[i] < '0' || date[i] > '9')
                return false;
        }
    }

    int mm, dd, yy;
    sscanf(date.c_str(), "%2d-%2d-%4d", &mm, &dd, &yy);

    if (mm < 1 || mm > 12)
        return false;

    if (dd < 1 || dd > 31)
        return false;

    if (dd == 31 && (mm == 4 || mm == 6 || mm == 9 || mm == 11 || mm == 2))
        return false;

    if (dd == 30 && mm == 2)
        return false;

    return true;
}

int main()
{
    string date;

    // Test cases
    date = "03-11-2000";
    if (!valid_date(date))
    {
        cerr << "Test case 1 failed" << endl;
        return EXIT_FAILURE;
    }

    date = "15-01-2012";
    if (valid_date(date))
    {
        cerr << "Test case 2 failed" << endl;
        return EXIT_FAILURE;
    }

    date = "04-0-2040";
    if (valid_date(date))
    {
        cerr << "Test case 3 failed" << endl;
        return EXIT_FAILURE;
    }

    date = "06-04-2020";
    if (!valid_date(date))
    {
        cerr << "Test case 4 failed" << endl;
        return EXIT_FAILURE;
    }

    date = "01-01-2007";
    if (!valid_date(date))
    {
        cerr << "Test case 5 failed" << endl;
        return EXIT_FAILURE;
    }

    date = "03-32-2011";
    if (valid_date(date))
    {
        cerr << "Test case 6 failed" << endl;
        return EXIT_FAILURE;
    }

    date = "";
    if (valid_date(date))
    {
        cerr << "Test case 7 failed" << endl;
        return EXIT_FAILURE;
    }

    date = "04-31-3000";
    if (valid_date(date))
    {
        cerr << "Test case 8 failed" << endl;
        return EXIT_FAILURE;
    }

    date = "06-06-2005";
    if (!valid_date(date))
    {
        cerr << "Test case 9 failed" << endl;
        return EXIT_FAILURE;
    }

    date = "21-31-2000";
    if (valid_date(date))
    {
        cerr << "Test case 10 failed" << endl;
        return EXIT_FAILURE;
    }

    date = "04-12-2003";
    if (!valid_date(date))
    {
        cerr << "Test case 11 failed" << endl;
        return EXIT_FAILURE;
    }

    date = "04122003";
    if (valid_date(date))
    {
        cerr << "Test case 12 failed" << endl;
        return EXIT_FAILURE;
    }

    date = "20030412";
    if (valid_date(date))
    {
        cerr << "Test case 13 failed" << endl;
        return EXIT_FAILURE;
    }

    date = "2003-04";
    if (valid_date(date))
    {
        cerr << "Test case 14 failed" << endl;
        return EXIT_FAILURE;
    }

    date = "2003-04-12";
    if (valid_date(date))
    {
        cerr << "Test case 15 failed" << endl;
        return EXIT_FAILURE;
    }

    date = "04-2003";
    if (valid_date(date))
    {
        cerr << "Test case 16 failed" << endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

[C]
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool valid_date(const char *date)
{
    if (strlen(date) != 10)
        return false;

    for (int i = 0; i < 10; i++)
    {
        if (i == 3 || i == 6)
        {
            if (date[i] != '-')
                return false;
        }
        else
        {
            if (date[i] < '0' || date[i] > '9')
                return false;
        }
    }

    int mm, dd, yy;
    sscanf(date, "%2d-%2d-%4d", &mm, &dd, &yy);

    if (mm < 1 || mm > 12)
        return false;

    if (dd < 1 || dd > 31)
        return false;

    if (dd == 31 && (mm == 4 || mm == 6 || mm == 9 || mm == 11 || mm == 2))
        return false;

    if (dd == 30 && mm == 2)
        return false;

    return true;
}

int main()
{
    char date[11];

    // Test cases
    strcpy(date, "03-11-2000");
    if (!valid_date(date))
    {
        fprintf(stderr, "Test case 1 failed
");
        return EXIT_FAILURE;
    }

    strcpy(date, "15-01-2012");
    if (valid_date(date))
    {
        fprintf(stderr, "Test case 2 failed
");
        return EXIT_FAILURE;
    }

    strcpy(date, "04-0-2040");
    if (valid_date(date))
    {
        fprintf(stderr, "Test case 3 failed
");
        return EXIT_FAILURE;
    }

    strcpy(date, "06-04-2020");
    if (!valid_date(date))
    {
        fprintf(stderr, "Test case 4 failed
");
        return EXIT_FAILURE;
    }

    strcpy(date, "01-01-2007");
    if (!valid_date(date))
    {
        fprintf(stderr, "Test case 5 failed
");
        return EXIT_FAILURE;
    }

    strcpy(date, "03-32-2011");
    if (valid_date(date))
    {
        fprintf(stderr, "Test case 6 failed
");
        return EXIT_FAILURE;
    }

    strcpy(date, "");
    if (valid_date(date))
    {
        fprintf(stderr, "Test case 7 failed
");
        return EXIT_FAILURE;
    }

    strcpy(date, "04-31-3000");
