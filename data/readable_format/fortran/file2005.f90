program test_foo10
  implicit none
  real, dimension(10,10) :: a, b
  integer :: i, j

  ! Initialize arrays
  a = 0.0
  b = 1.0

  call foo10(a, b)

  ! Output for inspection or perform checks
  do i = 1, 10
     do j = 1, 10
        write(*,*) 'a(', i, ',', j, ') = ', a(i,j), ' b(', i, ',', j, ') = ', b(i,j)
     end do
  end do
end program test_foo10

subroutine foo10(a, b)
  real, dimension(10,10), intent(inout) :: a, b
  integer :: k, i, j

  do k = 1, 4
     do i = 1, 10
        do j = 1, 10
           if (a(i,j) < k) then
              a(i,j) = a(i,j) + b(i,j)
              b(i,j) = a(i,j) - b(i,j)
           else
              a(i,j) = a(i,j) * 2
           endif
        end do
     end do
  end do
end subroutine foo10