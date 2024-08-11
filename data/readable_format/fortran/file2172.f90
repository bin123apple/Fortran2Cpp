program test_reduction
  implicit none
  integer :: i, j
  real, dimension(10,10) :: b, c
  real, dimension(10) :: a, d

  ! Initialize arrays with test values
  do i = 1, 10
     do j = 1, 10
        b(i, j) = real(i * j)
     end do
     d(i) = real(i)
  end do

  ! Execute the code
  do i = 1, 10
     do j = 1, 10
        if (i == 1) then
            a(i) = b(i, j) ! Adjusted to use the first row for the first element
        else
            a(i) = b(i-1, j)
        end if
        if (i < 10) then
            c(i+1, j) = d(i+1)
        end if
     end do
  end do

  ! Print the results
  print *, 'Array a:'
  print *, a
  print *, 'Array c:'
  do i = 1, 10
     print *, (c(i,j), j=1,10)
  end do

end program test_reduction