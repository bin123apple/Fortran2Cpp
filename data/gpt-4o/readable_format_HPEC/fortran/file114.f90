program DRB088_dynamic_storage_orig_yes
    use omp_lib
    implicit none
    integer, pointer :: counter

    allocate(counter)

    counter = 0

    !$omp parallel
    counter = counter+1
    !$omp end parallel

    print*,counter

    deallocate(counter)

end program
