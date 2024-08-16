subroutine ipow46(a, exponent, result)



implicit none
double precision a, result, dummy, q, r
integer exponent, n, n2
external randlc
double precision randlc
result = 1
if (exponent .eq. 0) return
q = a
r = 1
n = exponent


do while (n .gt. 1)
n2 = n/2
if (n2 * 2 .eq. n) then
dummy = randlc(q, q)
n = n2
else
dummy = randlc(r, q)
n = n-1
endif
end do
dummy = randlc(r, q)
result = r
return
end
