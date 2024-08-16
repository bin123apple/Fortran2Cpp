program DRB071_targetparallelfor_orig_no
    use omp_lib
    implicit none

    integer :: i, len
    integer, dimension(:), allocatable :: a

    allocate(a(len))

    do i = 1, len
        a(i) = i
    end do

    !$omp target map(a(1:len))
    !$omp parallel do
    do i = 1, len
        a(i) = a(i)+1
    end do
    !$omp end target

    deallocate(a)
end program
