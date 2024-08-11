program test_loop
  use, intrinsic :: iso_fortran_env, only: error_unit
  implicit none
  integer :: i
  integer, parameter :: n=8
  integer :: a(n)
  logical :: pass

  ! Call the original loop program as a subroutine
  call loop_program(a)

  ! Verify that the array was filled correctly
  pass = .true.
  do i=1,n
    if (a(i) /= i) then
      pass = .false.
      write(error_unit,*) "Test failed at index", i, "Expected", i, "Got", a(i)
    end if
  end do

  if (pass) then
    write(*,*) "Fortran test PASS"
  else
    write(*,*) "Fortran test FAIL"
  end if

contains

  subroutine loop_program(a)
    integer, intent(out) :: a(n)
    integer :: i

    do i = 1, n
      a(i) = i
    end do
  end subroutine loop_program

end program test_loop