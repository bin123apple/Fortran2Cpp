module clusfgt_mod
  implicit none
contains
  subroutine clusfgt(n, x, incx, target, index, nclus)
    integer, intent(in) :: n, incx
    real, intent(in) :: target
    real, intent(in) :: x(*)
    integer, intent(out) :: index(2,*), nclus
    integer :: i, ib, nb
    
    nclus = 0
    if (n < 1) return
    ib = 1
    nb = 0
    
    do i = 1, n
      if (x(ib) > target) then
        if (nb == 0 .or. ib > index(2, nb)) then
          nb = nb + 1
          index(1, nb) = i
        endif
        index(2, nb) = i
      endif
      ib = ib + incx
    end do
    
    nclus = nb
  end subroutine clusfgt
end module clusfgt_mod

program testClusfgt
  use clusfgt_mod
  implicit none
  integer, parameter :: maxClusters = 100
  integer :: nclus
  integer :: index(2, maxClusters)
  real, allocatable :: x(:)
  integer :: n, incx
  real :: target
  
  ! Test 1: A sequence with all elements greater than the target value
  n = 5
  allocate(x(n))
  x = [0.7, 0.8, 0.9, 1.0, 1.1]
  target = 0.6
  incx = 1
  call clusfgt(n, x, incx, target, index, nclus)
  print *, "Test 1: Number of clusters: ", nclus

  ! Add more tests as necessary...

end program testClusfgt