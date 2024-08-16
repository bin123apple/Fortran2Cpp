program DRB046_doall2_orig_no
    use omp_lib
    implicit none

    integer :: i, j
    integer :: a(100,100)

    !$omp parallel do private(j)
    do i = 1, 100
        do j = 1, 100
            a(i,j) = a(i,j)+1
        end do
    end do
    !$omp end parallel do
end program
