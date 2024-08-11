program test_range

implicit none

integer :: i, imax
parameter (imax = 3)
real :: a(0:imax), b(0:imax)
logical :: test_passed

! Initialize array b with some values
do i=0,imax
    b(i) = i * 2.0
end do

! Copy b into a
a(:) = b(:)

! Test: Check if arrays a and b are identical
test_passed = .true.
do i=0,imax
    if (a(i) /= b(i)) then
        test_passed = .false.
        exit
    endif
end do

if (test_passed) then
    print *, "Test Passed: Arrays are identical."
else
    print *, "Test Failed: Arrays are not identical."
endif

end program test_range