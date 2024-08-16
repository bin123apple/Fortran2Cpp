#include <vector>
#include <cstdlib>

void make_a_pile(int n, std::vector<int>& out)
{
    out.resize(n);
    out[0] = n;
    for (int i = 1; i < n; ++i) {
        out[i] = out[i-1] + 2;
    }
}

int main()
{
    std::vector<int> pile;
    make_a_pile(3, pile);
    if (pile != std::vector<int>({3, 5, 7})) {
        std::abort();
    }

    make_a_pile(4, pile);
    if (pile != std::vector<int>({4, 6, 8, 10})) {
        std::abort();
    }

    make_a_pile(5, pile);
    if (pile != std::vector<int>({5, 7, 9, 11, 13})) {
        std::abort();
    }

    make_a_pile(6, pile);
    if (pile != std::vector<int>({6, 8, 10, 12, 14, 16})) {
        std::abort();
    }

    make_a_pile(8, pile);
    if (pile != std::vector<int>({8, 10, 12, 14, 16, 18, 20, 22})) {
        std::abort();
    }
}

[C]
void make_a_pile(int n, int* out)
{
    int i;
    for (i = 0; i < n; ++i) {
        out[i] = 2 * i + 1;
    }
}

int main()
{
    int pile[8];
    make_a_pile(3, pile);
    if (pile[0] != 3 || pile[1] != 5 || pile[2] != 7) {
        abort();
    }

    make_a_pile(4, pile);
    if (pile[0] != 4 || pile[1] != 6 || pile[2] != 8 || pile[3] != 10) {
        abort();
    }

    make_a_pile(5, pile);
    if (pile[0] != 5 || pile[1] != 7 || pile[2] != 9 || pile[3] != 11 || pile[4] != 13) {
        abort();
    }

    make_a_pile(6, pile);
    if (pile[0] != 6 || pile[1] != 8 || pile[2] != 10 || pile[3] != 12 || pile[4] != 14 || pile[5] != 16) {
        abort();
    }

    make_a_pile(8, pile);
    if (pile[0] != 8 || pile[1] != 10 || pile[2] != 12 || pile[3] != 14 || pile[4] != 16 || pile[5] != 18 || pile[6] != 20 || pile[7] != 22) {
        abort();
    }
}

[Python]
def make_a_pile(n):
    return [2*i+1 for i in range(n)]

if make_a_pile(3) != [3, 5, 7]:
    exit(1)

if make_a_pile(4) != [4, 6, 8, 10]:
    exit(1)

if make_a_pile(5) != [5, 7, 9, 11, 13]:
    exit(1)

if make_a_pile(6) != [6, 8, 10, 12, 14, 16]:
    exit(1)

if make_a_pile(8) != [8, 10, 12, 14, 16, 18, 20, 22]:
    exit(1)

[Rust]
fn make_a_pile(n: usize) -> Vec<i32> {
    let mut out = Vec::with_capacity(n);
    for i in 0..n {
        out.push(2 * i + 1);
    }
    out
}

fn main() {
    assert_eq!(make_a_pile(3), vec![3, 5, 7]);
    assert_eq!(make_a_pile(4), vec![4, 6, 8, 10]);
    assert_eq!(make_a_pile(5), vec![5, 7, 9, 11, 13]);
    assert_eq!(make_a_pile(6), vec![6, 8, 10, 12, 14, 16]);
    assert_eq!(make_a_pile(8), vec![8, 10, 12, 14, 16, 18, 20, 22]);
}

[Go]
func make_a_pile(n int) []int {
    out := make([]int, n)
    for i := 0; i < n; i++ {
        out[i] = 2 * i + 1
    }
    return out
}

func main() {
    if !reflect.DeepEqual(make_a_pile(3), []int{3, 5, 7}) {
        os.Exit(1)
    }

    if !reflect.DeepEqual(make_a_pile(4), []int{4, 6, 8, 10}) {
        os.Exit(1)
    }

    if !reflect.DeepEqual(make_a_pile(5), []int{5, 7, 9, 11, 13}) {
        os.Exit(1)
    }

    if !reflect.DeepEqual(make_a_pile(6), []int{6, 8, 10, 12, 14, 16}) {
        os.Exit(1)
    }

    if !reflect.DeepEqual(make_a_pile(8), []int{8, 10, 12, 14, 16, 18, 20, 22}) {
        os.Exit(1)
    }
}

[C#]
using System;
using System.Linq;

class Program
{
    static void Main()
    {
        if (!Enumerable.SequenceEqual(MakeAPile(3), new[] { 3, 5, 7 }))
        {
            Environment.Exit(1);
        }

        if (!Enumerable.SequenceEqual(MakeAPile(4), new[] { 4, 6, 8, 10 }))
        {
            Environment.Exit(1);
        }

        if (!Enumerable.SequenceEqual(MakeAPile(5), new[] { 5, 7, 9, 11, 13 }))
        {
            Environment.Exit(1);
        }

        if (!Enumerable.SequenceEqual(MakeAPile(6), new[] { 6, 8, 10, 12, 14, 16 }))
        {
            Environment.Exit(1);
        }

        if (!Enumerable.SequenceEqual(MakeAPile(8), new[] { 8, 10, 12, 14, 16, 18, 20, 22 }))
        {
            Environment.Exit(1);
        }
    }

    static int[] MakeAPile(int n)
    {
        return Enumerable.Range(0, n).Select(i => 2 * i + 1).ToArray();
    }
}

[Java]
import java.util.Arrays;

public
