program DRB095_doall2_taskloop_orig_yes
    use omp_lib
    use DRB095
    implicit none

    integer :: len, i, j
    len = 100
    allocate (a(len,len))

    !$omp parallel
        !$omp single
            !$omp taskloop
            do i = 1, len
                do j = 1, len
                    a(i,j) = a(i,j)+1
                end do
            end do
            !$omp end taskloop
        !$omp end single
    !$omp end parallel

    print 100, a(50,50)
    100 format ('a(50,50) =',i3)

end program
