program range_test

implicit none

integer :: i, imax
parameter (imax = 3)

real :: a(0:imax), b(0:imax)
logical :: test_passed

! Initialize array b with some test data
do i=0,imax
    b(i) = i * 1.0
end do

! Copying elements from array b to array a
a(:) = b(:)

! Test if elements of a match b
test_passed = .true.
do i=0,imax
    if (a(i) /= b(i)) then
        test_passed = .false.
        exit
    end if
end do

if (test_passed) then
    print *, "Test Passed: Arrays a and b are equal."
else
    print *, "Test Failed: Arrays a and b are not equal."
end if

end program range_test