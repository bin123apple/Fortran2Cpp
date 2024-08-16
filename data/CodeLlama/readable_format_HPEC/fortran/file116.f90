program DRB080_func_arg_orig_yes
    use omp_lib
    use global
    implicit none

    integer :: i
    i = 0

    !$omp parallel
    call f1(i)
    !$omp end parallel

    if (i /= 0) then
        print 100, i
        100 format ('i =',i3)
    end if
end program
