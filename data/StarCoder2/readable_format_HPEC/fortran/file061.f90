program DRB139_worksharingcritical_orig_no
    use omp_lib
    implicit none

    integer :: i
    i = 1

    !$OMP PARALLEL SECTIONS
    !$OMP SECTION
        !$OMP CRITICAL (NAME)
            !$OMP PARALLEL
                !$OMP SINGLE
                i = i + 1
                !$OMP END SINGLE
            !$OMP END PARALLEL
        !$OMP END CRITICAL (NAME)
    !$OMP END PARALLEL SECTIONS

    print 100,i
    100 format ("i = ", 3i8)
end program
