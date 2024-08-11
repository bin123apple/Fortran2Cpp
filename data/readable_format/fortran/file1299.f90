! test.f90
program test
  implicit none
  integer :: i
  integer, dimension(10) :: a

  i = 0
  a = (/1, 2, 3, 4, 5, 6, 7, 8, 9, 10/)

  ! Testing private variable
  !$acc parallel private(i)
  i = 10
  !$acc end parallel
  print *, 'Expected i=10, Actual i=', i

  ! Testing firstprivate array
  !$acc parallel firstprivate(a)
  a(1) = 20
  !$acc end parallel
  print *, 'Expected a(1)=20, Actual a(1)=', a(1)

end program test