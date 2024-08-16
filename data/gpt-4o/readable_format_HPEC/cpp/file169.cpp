void ipow46(double a, int exponent, double& result)
{
    double dummy, q, r;
    int n, n2;
    result = 1;
    if (exponent == 0) return;
    q = a;
    r = 1;
    n = exponent;

    while (n > 1)
    {
        n2 = n/2;
        if (n2 * 2 == n)
        {
            dummy = randlc(q, q);
            n = n2;
        } 
        else 
        {
            dummy = randlc(r, q);
            n = n-1;
        }
    }
    dummy = randlc(r, q);
    result = r;
}
