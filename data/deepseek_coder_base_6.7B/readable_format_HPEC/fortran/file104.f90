program DRB023_sections1_orig_yes
    use omp_lib
    implicit none

    integer :: i
    i = 0

    !$omp parallel sections
    !$omp section
    i=1
    !$omp section
    i=2
    !$omp end parallel sections

    print 100, i
    100 format ("i=",i3)

end program
