program DRB073_doall2_orig_yes
    use omp_lib
    implicit none

    integer :: i, j, len
    integer, dimension(:,:), allocatable :: a
    len = 100

    allocate (a(len,len))

    !$omp parallel do
    do i = 1, 100
        do j = 1, 100
            a(i,j) = a(i,j)+1
        end do
    end do
    !$omp end parallel do


    deallocate(a)
end program
