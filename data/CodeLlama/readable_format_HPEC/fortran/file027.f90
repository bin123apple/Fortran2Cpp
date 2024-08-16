program DRB110_ordered_orig_no
    use omp_lib
    implicit none

    integer x, i
    x=0
    
    !$omp parallel do ordered
    do i = 1, 100
        !$omp ordered
        x = x+1
        !$omp end ordered
    end do
    !$omp end parallel do    

    print*,'x =',x
end program
