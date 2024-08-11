program test_program
  use, intrinsic :: iso_fortran_env, only: stdout => output_unit
  implicit none
  character(len=:), allocatable :: chr
  character(len=21) :: expected = "ABCDEFGHIJKLMNOPQRSTU"
  logical :: test_passed
  integer :: i

  chr = test2(10) ! Call test2 to generate the string

  if (len(chr) /= 21) then
    write(stdout,*) "Length check failed."
    stop
  end if

  test_passed = .true.
  do i = 1, len(chr)
    if (chr(i:i) /= expected(i:i)) then
      test_passed = .false.
      exit
    end if
  end do

  if (.not. test_passed) then
    write(stdout,*) "Content check failed."
    stop
  else
    write(stdout,*) "All tests passed successfully."
  end if

contains

  pure function f(x) result(res)
    integer, intent(in) :: x
    integer :: res
    res = 2*x + 1
  end function f

  function test2(x) result(r)
    integer, intent(in) :: x
    character(len=:), allocatable :: r
    integer :: i, len_r

    len_r = f(x) ! Determine the length of r based on function f
    allocate(character(len=len_r) :: r) ! Allocate r with the calculated length

    do i = 1, len_r
      r(i:i) = achar(mod(i, 32) + iachar('@'))
    end do
  end function test2

end program test_program