program test
  implicit none
  integer :: a
  a = 0
  if (.true.) then
     ! No action
  else
     a = 1
  end if
  print *, 'Value of a:', a
end program test