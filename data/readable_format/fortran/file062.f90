program test_offset
  implicit none
  real, allocatable :: crd(:)
  integer :: length
  real :: off, scale
  integer :: i

  length = 3
  allocate(crd(length))
  
  ! Test values
  off = 2.0
  scale = 3.0
  crd = (/1.0, 2.0, 3.0/)

  call offset(off, scale, crd, length)
  
  ! Check results
  do i = 1, length
     print *, 'crd(', i, ') = ', crd(i)
  end do

  deallocate(crd)

contains

  subroutine offset (off, scale, crd, length)
    real, intent(in) :: off, scale
    real, intent(inout) :: crd(:)
    integer, intent(in) :: length

    do i = 1, length
       crd(i) = scale * crd(i) + off
    end do
  end subroutine offset

end program test_offset