module mod_p
  implicit none
contains
  subroutine test_p()
    integer :: j, a(2,6), i(3,2)
    integer, allocatable :: ai(:,:)

    ! Initialize arrays
    a(1,:) = (/ (j , j=1,6) /)
    a(2,:) = (/ (-10*j , j=1,6) /)

    i(:,1) = (/ 1, 3, 5 /)
    i(:,2) = (/ 4, 5, 6 /)

    ! Associate block equivalent operation
    allocate(ai(2,3))
    ai(:,1) = a(:,i(1,1))
    ai(:,2) = a(:,i(2,1))
    ai(:,3) = a(:,i(3,1))

    ! Assertions
    if (any(shape(ai) /= [2, 3])) stop "Shape mismatch"
    if (any(reshape(ai, [6]) /= [1 , -10, 3, -30, 5, -50])) stop "Value mismatch"

    print *, "Fortran tests passed."
  end subroutine test_p
end module mod_p

program main
  use mod_p
  call test_p()
end program main