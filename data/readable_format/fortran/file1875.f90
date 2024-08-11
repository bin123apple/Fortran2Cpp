subroutine foo ()
  implicit none
  integer :: p, k
  integer :: sum_p, sum_k
  sum_p = 0
  sum_k = 0

  do p = 1,5
     sum_p = sum_p + p
  enddo

  do k = 2,6
     sum_k = sum_k + k
  enddo

  print *, "Sum of p: ", sum_p
  print *, "Sum of k: ", sum_k
end subroutine

program test
call foo()
end program