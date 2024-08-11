program test_main
  implicit none
  integer, parameter :: N = 100
  integer :: a(N,N,N), sa, result
  double precision :: b(N,N,N), sb
  real :: c(N,N,N), sc
  integer :: i, j, k

  sa = 0
  sb = 0.0d0
  sc = 0.0

  do k = 1, N
     do j = 1, N
        do i = 1, N
           a(i,j,k) = 1
        end do
     end do
  end do

  do k = 1, N
     do j = 1, N
        do i = 1, N
           b(i,j,k) = 0.5d0
        end do
     end do
  end do

  do k = 1, N
     do j = 1, N
        do i = 1, N
           c(i,j,k) = 0.25
        end do
     end do
  end do
  
  do k = 1, N
     do j = 1, N
        do i = 1, N
           sa = sa + a(i,j,k)
        end do
     end do
  end do

  do k = 1, N
     do j = 1, N
        do i = 1, N
           sb = sb + b(i,j,k)
        end do
     end do
  end do
  
  do k = 1, N
     do j = 1, N
        do i = 1, N
           sc = sc + c(i,j,k)
        end do
     end do
  end do
  
  result = 0
  if(sa /= N**3 .or. abs(sb-(N**3*0.5d0)) > 0.000001d0 .or. abs(sc-(N**3*0.25)) > 0.0001) then
     result = -1
  end if

  if(result == 0) then
     print *, "PASS"
  else
     print *, "ERROR"
  end if

end program test_main