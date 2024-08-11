module foo_mod
contains
  subroutine foo(a)
    integer, intent(out) :: a(30)
    integer :: i

    ! Using OpenMP to parallelize the loop
    !$omp parallel do private(i)
    do i = 1, 30
      if (mod(i,2)==0) then
        a(i) = 5
      else if (i <= 15) then
        a(i) = 2
      else
        a(i) = 1
      end if
    end do
    !$omp end parallel do
  end subroutine foo
end module foo_mod

program test_foo
  use foo_mod
  implicit none
  integer :: a(30), i

  call foo(a)

  print *, "Fortran Stdout: Testing array modifications."
  do i = 1, 30
    print *, "a(", i, ") = ", a(i)
  end do
end program test_foo