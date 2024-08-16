program DRB014_outofbounds_orig_yes
    use omp_lib
    implicit none

    integer :: i, j, n, m
    real, dimension (:,:), allocatable :: b

    n = 100
    m = 100

    allocate (b(n,m))

    !$omp parallel do private(i)
    do j = 2, n
        do i = 1, m
            b(i,j) = b(i-1,j)
        end do
    end do
    !$omp end parallel do
    print*,"b(50,50)=",b(50,50)

    deallocate(b)
end program
