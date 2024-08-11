program testDemo

real(kind=8) :: x(1001),y(1001)
integer :: j
real(kind=8) :: max_y, expected_max_y
real(kind=8), parameter :: tolerance = 1.0E-6

do j=1,1001
    x(j) = -20.d0 + (j-1)*40.d0/1000.d0
    y(j) = sin(x(j)) / x(j)
end do

max_y = maxval(y)

! Assuming an expected max value for the sake of this example
expected_max_y = 0.217234

if (abs(max_y - expected_max_y) > tolerance) then
    print *, "Test failed: max value of y is incorrect."
else
    print *, "Test passed: max value of y is correct."
end if

! Example test for a specific value of x and y
if (abs(x(501) + 0.0) > tolerance .or. abs(y(501) - 1.0) > tolerance) then
    print *, "Test failed for x(501) or y(501)."
else
    print *, "Test passed for x(501) and y(501)."
end if

end program testDemo