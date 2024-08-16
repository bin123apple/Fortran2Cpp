program DRB101_task_value_orig_no
    use omp_lib
    use DRB101
    implicit none

    integer :: i
    allocate (a(100))

    !$omp parallel
        !$omp single
        do i = 1, 100
            call gen_task(i)
        end do
        !$omp end single
    !$omp end parallel

    do i = 1, 100
        if (a(i) /= i+1) then
            print*,'warning: a(',i,') =',a(i),' not expected',i+1
        end if
!        print*,a(i),i+1
    end do
end program
