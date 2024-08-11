! file: omp_test.f90
program omp_test
    use omp_lib
    implicit none
    integer :: i

    !$omp parallel
        !$omp do
        do i = 1, 10
            print *, 'Fortran loop 1 thread', omp_get_thread_num(), 'i=', i
        end do

        !$omp do
        do i = 1, 10
            print *, 'Fortran loop 2 thread', omp_get_thread_num(), 'i=', i
        end do

        !$omp sections
            !$omp section
            print *, 'Fortran section 1 executed by thread', omp_get_thread_num()
            !$omp section
            print *, 'Fortran section 2 executed by thread', omp_get_thread_num()
        !$omp end sections
    !$omp end parallel
    
end program omp_test