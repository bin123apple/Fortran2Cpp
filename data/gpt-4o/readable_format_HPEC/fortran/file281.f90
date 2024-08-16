program DRB080_func_arg_orig_yes
    use omp_lib
    implicit none

    integer :: i

    i = 0

    !$omp parallel
    call f1(i)
    !$omp end parallel

    print*,"i = ",i
end program
