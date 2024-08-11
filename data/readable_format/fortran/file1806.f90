program test_program
  implicit none
  integer, parameter :: n = 10
  real :: a(n)
  integer :: i
  
  ! Call the subroutine
  call testg77(n, a)
  
  ! Test output or behavior here if needed
  ! For demonstration: Simply print a message
  print *, "Test completed. Check output above for correctness."

contains

  subroutine testg77(n, a)
    implicit none
    integer :: n
    real, dimension(n) :: a
    real :: b(n)
    integer :: i

    do i = 1, 10
      if (i .gt. 4) goto 100
      print *, i
    end do

    goto 200
100 continue
200 continue

    return
  end subroutine testg77

end program test_program