! Define the subroutine with an added output parameter for testing
subroutine pr40421(j, q, r, sum_stu)
  implicit none
  integer, intent(in) :: j
  double precision, intent(in) :: q(1,1), r(1,1,3)
  double precision, intent(out) :: sum_stu
  integer :: i, m, n
  double precision :: s, t, u
  sum_stu = 0.0
  do i=1,2
    do m=1,j
      do n=1,1
        s=q(n,m)*r(n,m,1)
        t=q(n,m)*r(n,m,2)
        u=q(n,m)*r(n,m,3)
        sum_stu = sum_stu + s + t + u
      end do
    end do
  end do
end subroutine pr40421

! Main program for testing
program test
  implicit none
  double precision :: q(1,1), r(1,1,3), sum_stu
  integer :: j

  ! Initialize test case
  j = 1
  q(1,1) = 2.0
  r(1,1,1) = 1.0
  r(1,1,2) = 2.0
  r(1,1,3) = 3.0
  
  ! Call the subroutine
  call pr40421(j, q, r, sum_stu)
  
  ! Output the result for verification
  print *, 'Sum of s, t, and u: ', sum_stu
  
  ! Check the result
  if (sum_stu == 12.0) then
    print *, 'Test passed.'
  else
    print *, 'Test failed.'
  end if
end program test