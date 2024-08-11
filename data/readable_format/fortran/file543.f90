module kpoints
    
    implicit none

    ! Declarations
    integer nkpoints
    real, dimension (:, :), allocatable :: special_k
    real, dimension (:, :), allocatable :: special_k_orig
    real, dimension (:), allocatable :: weight_k
    real, dimension (:), allocatable :: weight_k_orig
    real, dimension (:, :), allocatable :: scale_k
    character (len = 40) kptpreference 

end module kpoints

program test_kpoints
    use kpoints
    implicit none

    integer :: i, j
    integer, parameter :: dim1 = 3, dim2 = 2

    ! Initialize nkpoints
    nkpoints = 5
    print *, "nkpoints initialized to: ", nkpoints

    ! Allocate and fill special_k
    allocate(special_k(dim1, dim2))
    do i = 1, dim1
        do j = 1, dim2
            special_k(i, j) = i * j * 0.5
        end do
    end do
    print *, "special_k allocated and filled."
    ! Print special_k values
    do i = 1, dim1
        print *, (special_k(i, j), j = 1, dim2)
    end do

    ! Test character string assignment
    kptpreference = "High symmetry path"
    print *, "kptpreference set to: ", kptpreference

    ! Clean up
    deallocate(special_k)
    print *, "special_k deallocated."

end program test_kpoints