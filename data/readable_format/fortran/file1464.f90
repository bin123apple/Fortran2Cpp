program main
  implicit none
  integer, dimension(2) :: b
  b = fun(size(b))
  if (b(1) /= 1 .or. b(2) /= 2) STOP 1
  print *, "Test passed: b is correctly initialized."
contains
  pure function fun(n) 
    integer, intent(in) :: n
    integer :: fun(n)
    integer :: i
    do i = 1, n
        fun(i) = i
    end do
  end function fun
end program main