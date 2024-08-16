program DRB126_firstprivatesections_orig_no
    use omp_lib
    implicit none

    integer :: section_count

    section_count = 0

    call omp_set_dynamic(.FALSE.)
    call omp_set_num_threads(1)

    !$omp parallel
    !$omp sections firstprivate( section_count )
        !$omp section
        section_count = section_count+1
        print 100, section_count
        100 format ('section_count =',3i8)

        !$omp section
        section_count = section_count+1
        print 101, section_count
        101 format ('section_count =',3i8)
    !$omp end sections
    !$omp end parallel
end program
