program test
  implicit none
  integer :: r

  r = 0
  call foo (r)

  if (r == 11) then
    print *, "Test passed, r = ", r
  else
    print *, "Test failed, r = ", r
    call abort
  end if

contains

  subroutine foo (r)
    integer :: i, r
    !omp parallel
    !omp single
    !omp target teams distribute parallel do reduction (+: r)
      do i = 1, 10
        r = r + 1
      end do
      r = r + 1
    !omp end single
    !omp end parallel
  end subroutine

end program test