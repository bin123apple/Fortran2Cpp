program DRB109_orderedmissing_orig_yes
    use omp_lib
    implicit none

    integer x,i

    !$omp parallel do ordered
    do i = 1, 100
        x = x+1
    end do
    !$omp end parallel do

    print*,'x =',x

end program
