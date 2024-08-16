program DRB009_lastprivatemissing_orig_yes
    use omp_lib
    implicit none

    integer :: i, x, len
    len = 10000

    !$omp parallel do private(i)
    do i = 0, len
        x = i
    end do
    !$omp end parallel do

    write(*,*) 'x =', x
end program
