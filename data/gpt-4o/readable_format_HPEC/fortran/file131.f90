program DRB088_dynamic_storage_orig_yes
    use omp_lib
    use DRB088
    implicit none

    allocate(counter)

    counter = 0

    !$omp parallel
    call foo()
    !$omp end parallel

    print*,counter

    deallocate(counter)

end program
