program testMain
  implicit none
  integer, parameter :: N = 5
  integer :: random_array(N), ans_val, val, result, i
  real :: tmp(N)

  ! Predefined test array
  random_array = [100, 200, 300, 400, 500]

  ans_val = 0
  do i=1, N
     ans_val = max(ans_val, random_array(i))
  enddo

  val = 0
  do i=1, N
     val = max(val, random_array(i))
  enddo

  if(val .ne. ans_val) then
     result = -1
  else
     result = 0
  endif

  if (result .eq. 0) then
     write(*,*) "TEST PASS"
  else
     write(*,*) "TEST FAIL"
  end if
end program testMain