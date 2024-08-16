program DRB099_targetparallelfor2_orig_no
    use omp_lib
    use DRB099
    implicit none

    integer :: i, len
  integer, parameter :: dp = kind(1.0d0)
    real(dp), dimension(:), allocatable :: a,b
    real :: x

    len = 1000

    allocate(a(len))
    allocate(b(len))

    do i = 1, len
        a(i) = (real(i,dp))/2.0
        b(i) = 0.0
    end do

    x=foo(a,b,len)
    print*,'b(50) =',b(50)
  
    deallocate(a,b)
end program
