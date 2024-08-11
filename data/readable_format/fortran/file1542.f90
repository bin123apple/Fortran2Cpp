program test
  implicit none
  
  ! Declare variables used in the program
  integer :: i ,j
  real :: a(0:1,0:1) ,b(0:1,0:1)

  ! Initialize arrays
  a = 0.
  b = 0.
  
  ! First DO loop
  DO i=0,1 
     DO j=0,1
        a(i,j) = add(i,j,abs(i-j))
        b(i,j) = add2(i,j,abs(i-j))
     END DO
  END DO
  call check_err (a, 10.)
  call check_err (b, 6.)

  ! Reset arrays to zero
  a = 0.
  b = 0.
  
  ! Second identical DO loop for demonstration
  DO i=0,1 
     DO j=0,1
        a(i,j) = add(i,j,abs(i-j))
        b(i,j) = add2(i,j,abs(i-j))
     END DO
  END DO
  call check_err (a, 10.)
  call check_err (b, 6.)

contains

  ! Function definitions directly included
  pure real function add(i,j,k)
    integer ,intent(in) :: i,j,k
    add = real(i+j+k)+1.
  end function add

  pure real function add2(i,j,k)
    integer ,intent(in) :: i,j,k
    add2 = real(i+j+k)
  end function add2

  subroutine check_err(a, s)
    real, dimension(:,:), intent(in) :: a
    real, intent(in) :: s
    if (abs(sum(a) - s) > 1e-5) STOP 1
  end subroutine check_err

end program test