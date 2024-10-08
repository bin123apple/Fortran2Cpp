program DRB026_targetparallelfor_orig_yes
    use omp_lib
    implicit none

    integer :: i, len
    integer, dimension(:), allocatable :: a

    len = 1000

    allocate (a(len))

    do i = 1, len
        a(i) = i
    end do

    !$omp target map(a)
        !$omp parallel do
        do i = 1, len-1
            a(i) = a(i+1) + 1
        end do
        !$omp end parallel do
    !$omp end target

    do i = 1, len
        write(6,*) 'Values for i and a(i) are:', i, a(i)
    end do

    deallocate(a)
end program
