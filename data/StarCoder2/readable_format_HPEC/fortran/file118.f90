program DRB094_doall2_ordered_orig_no
    use omp_lib
    use DRB094
    implicit none

    integer :: len, i, j
    len = 100

    allocate (a(len,len))

    !$omp parallel do ordered(2)
    do i = 1, len
        do j = 1, len
            a(i,j) = a(i,j)+1
            !$omp ordered depend(sink:i-1,j) depend (sink:i,j-1)
            print*,'test i =',i,'  j =',j
            !$omp ordered depend(source)
        end do
    end do
    !$omp end parallel do


end program
