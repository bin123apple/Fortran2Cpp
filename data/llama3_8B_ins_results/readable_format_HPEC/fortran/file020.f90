program DRB059_lastprivate_orig_no
    use omp_lib
    implicit none
    !$omp parallel
    call foo()
    !$omp end parallel
contains
    subroutine foo()
        integer :: i, x
        !$omp parallel do private(i) lastprivate(x)
        do i = 1, 100
            x = i
        end do
        !$omp end parallel do
        print 100, x
        100 format ("x =",i3)
    end subroutine foo
end program
