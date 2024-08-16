#include <iostream>
#include <vector>

using namespace std;

int get_matrix_triples(int n) {
  vector<int> a(n);
  vector<vector<int>> sum(n+1, vector<int>(3, 0));
  vector<vector<int>> sum2(n+1, vector<int>(3, 0));

  // Initialize arrays
  for (int i = 0; i < n; i++) {
    a[i] = (i*i - i + 1) % 3;
    sum[i+1][0] = sum[i][0];
    sum[i+1][a[i]+1] = sum[i+1][a[i]+1] + 1;
  }

  // Compute sums for times = 1 and 2
  for (int times = 1; times <= 2; times++) {
    for (int i = 0; i < n; i++) {
      sum2[i+1][0] = sum2[i][0];
      for (int j = 0; j < 3; j++) {
        sum2[i+1][(a[i] + j) % 3 + 1] = sum2[i+1][(a[i] + j) % 3 + 1] + sum[i][j+1];
      }
    }
    sum = sum2;
    sum2 = vector<vector<int>>(n+1, vector<int>(3, 0));
  }

  return sum[n+1][0];
}

int main() {
  int n, result;

  // Test cases
  result = get_matrix_triples(5);
  if (result != 1) {
    cout << "Assertion failed: get_matrix_triples(5) == 1" << endl;
    return 1;
  }

  result = get_matrix_triples(6);
  if (result != 4) {
    cout << "Assertion failed: get_matrix_triples(6) == 4" << endl;
    return 1;
  }

  result = get_matrix_triples(10);
  if (result != 36) {
    cout << "Assertion failed: get_matrix_triples(10) == 36" << endl;
    return 1;
  }

  result = get_matrix_triples(100);
  if (result != 53361) {
    cout << "Assertion failed: get_matrix_triples(100) == 53361" << endl;
    return 1;
  }

  return 0;
}

[C#]
using System;
using System.Collections.Generic;

class Program
{
    static int GetMatrixTriples(int n)
    {
        var a = new int[n];
        var sum = new int[n + 1, 3];
        var sum2 = new int[n + 1, 3];

        // Initialize arrays
        for (int i = 0; i < n; i++)
        {
            a[i] = (i * i - i + 1) % 3;
            sum[i + 1, 0] = sum[i, 0];
            sum[i + 1, a[i] + 1] = sum[i + 1, a[i] + 1] + 1;
        }

        // Compute sums for times = 1 and 2
        for (int times = 1; times <= 2; times++)
        {
            for (int i = 0; i < n; i++)
            {
                sum2[i + 1, 0] = sum2[i, 0];
                for (int j = 0; j < 3; j++)
                {
                    sum2[i + 1, (a[i] + j) % 3 + 1] = sum2[i + 1, (a[i] + j) % 3 + 1] + sum[i, j + 1];
                }
            }
            sum = sum2;
            sum2 = new int[n + 1, 3];
        }

        return sum[n + 1, 0];
    }

    static void Main(string[] args)
    {
        int n, result;

        // Test cases
        result = GetMatrixTriples(5);
        if (result != 1)
        {
            Console.WriteLine("Assertion failed: GetMatrixTriples(5) == 1");
            return;
        }

        result = GetMatrixTriples(6);
        if (result != 4)
        {
            Console.WriteLine("Assertion failed: GetMatrixTriples(6) == 4");
            return;
        }

        result = GetMatrixTriples(10);
        if (result != 36)
        {
            Console.WriteLine("Assertion failed: GetMatrixTriples(10) == 36");
            return;
        }

        result = GetMatrixTriples(100);
        if (result != 53361)
        {
            Console.WriteLine("Assertion failed: GetMatrixTriples(100) == 53361");
            return;
        }
    }
}

[Java]
import java.util.Arrays;

class Program {
    static int getMatrixTriples(int n) {
        int[] a = new int[n];
        int[][] sum = new int[n + 1][3];
        int[][] sum2 = new int[n + 1][3];

        // Initialize arrays
        for (int i = 0; i < n; i++) {
            a[i] = (i * i - i + 1) % 3;
            sum[i + 1][0] = sum[i][0];
            sum[i + 1][a[i] + 1] = sum[i + 1][a[i] + 1] + 1;
        }

        // Compute sums for times = 1 and 2
        for (int times = 1; times <= 2; times++) {
            for (int i = 0; i < n; i++) {
                sum2[i + 1][0] = sum2[i][0];
                for (int j = 0; j < 3; j++) {
                    sum2[i + 1][(a[i] + j) % 3 + 1] = sum2[i + 1][(a[i] + j) % 3 + 1] + sum[i][j + 1];
                }
            }
            sum = sum2;
            sum2 = new int[n + 1][3];
        }

        return sum[n + 1][0];
    }

    public static void main(String[] args) {
        int n, result;

        // Test cases
        result = getMatrixTriples(5);
        if (result != 1) {
            System.out.println("Assertion failed: getMatrixTriples(5) == 1");
            return;
        }

        result = getMatrixTriples(6);
        if (result != 4) {
            System.out.println("Assertion failed: getMatrixTriples(6) == 4");
            return;
        }

        result = getMatrixTriples(10);
        if (result != 36) {
            System.out.println("Assertion failed: getMatrixTriples(10) == 36");
            return;
        }

        result = getMatrixTriples(100);
        if (result != 53361) {
            System.out.println("Assertion failed: getMatrixTriples(100) == 53361");
            return;
        }
    }
}

[JavaScript]
function getMatrixTriples(n) {
    var a = new Array(n);
    var sum = new Array(n + 1);
    var sum2 = new Array(n + 1);

    // Initialize arrays
    for (var i = 0; i < n; i++) {
        a[i] = (i * i - i + 1) % 3;
        sum[i + 1] = sum[
