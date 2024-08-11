program test_program
implicit none

integer, allocatable :: arr(:)
integer :: i

! Allocate and set values
allocate(arr(6))
arr = [(i, i=1, 6)]

! Check values
do i=1, size(arr)
    if (arr(i) /= i) then
        print *, 'Mismatch in arr at position', i
        stop
    endif
enddo

print *, 'Fortran test passed.'

end program test_program