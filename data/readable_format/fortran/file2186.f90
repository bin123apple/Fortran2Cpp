! Filename: alloc_test.f90
program alloc_test
  implicit none
  integer :: i
  integer, allocatable :: a(:)

  ! Allocate array a with a size of 4
  allocate(a(4), stat=i)
  if (i /= 0) then
     print *, "Fortran Stdout: Allocation of a failed, error code:", i
     stop
  end if

  ! Resize array a to a different size, which is not directly supported in Fortran, hence reallocate.
  ! Attempt to simulate a condition where reallocation might "fail" by checking the size.
  if (size(a) == 4) then
    deallocate(a)
    allocate(a(3), stat=i)
    if (i /= 0) then
       print *, "Fortran Stdout: Reallocation of a failed, error code:", i
       stop
    endif
  endif

  ! Check the allocation and size of array a
  if (.not. allocated(a) .or. size(a) /= 3) then
    print *, "Fortran Stdout: Unit test failed"
    stop
  else
    print *, "Fortran Stdout: Unit test passed"
  end if

end program alloc_test