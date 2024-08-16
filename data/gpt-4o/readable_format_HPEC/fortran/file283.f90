program DRB123_taskundeferred_orig_yes
    use omp_lib
    implicit none

    integer :: var, i
    var = 0

    !$omp parallel sections
    do i = 1, 10
        !$omp task shared(var) 
        var = var+1;
        !$omp end task
    end do
    !$omp end parallel sections

    print 100, var
    100 format ('var =', 3i8)
end program
