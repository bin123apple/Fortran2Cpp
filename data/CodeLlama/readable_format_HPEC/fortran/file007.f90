program DRB086_static_data_member_orig_yes
    use omp_lib
    use DRB086
    implicit none

    type(A) :: c
    c = A(0,0)

    !$omp parallel
    call foo()
    !$omp end parallel

    print *,counter,pcounter
end program
