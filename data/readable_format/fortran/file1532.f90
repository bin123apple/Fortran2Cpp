program test_per_getcof
  implicit none
  double precision, allocatable :: coffs(:), g(:)
  integer :: npt, m, i

  npt = 5
  m = 4
  allocate(coffs(npt), g(m))

  ! Initialize coffs with some values
  coffs = (/1.0, 2.0, 3.0, 4.0, 5.0/)

  call per_getcof(coffs, npt, g, m)

  print *, 'g:'
  do i = 1, m
     print *, g(i)
  end do

  deallocate(coffs, g)
end program test_per_getcof

subroutine per_getcof(coffs,npt,g,m)
  double precision coffs(npt), g(m)
  integer j

  do j = 1, m
     g(j) = -coffs(j+1)
  end do
end subroutine per_getcof