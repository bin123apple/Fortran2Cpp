program DRB093_doall2_collapse_orig_no
    use omp_lib
    use DRB093
    implicit none

    integer :: len, i, j
    len = 100

    allocate (a(len,len))

    !$omp parallel do collapse(2)
    do i = 1, len
        do j = 1, len
            a(i,j) = a(i,j)+1
        end do
    end do
    !$omp end parallel do
end program
