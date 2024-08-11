module bind_c_array_params
    use, intrinsic :: iso_c_binding
    implicit none

contains
    subroutine sub0(assumed_array, n) bind(c)
        integer(c_int), dimension(*), intent(inout) :: assumed_array
        integer(c_int), value :: n
        integer :: i
        do i = 1, n
            assumed_array(i) = assumed_array(i) + 1
        end do
    end subroutine sub0

    subroutine sub1(deferred_array, n) bind(c)
        integer(c_int), dimension(:), intent(inout) :: deferred_array
        integer(c_int), value :: n
        integer :: i
        do i = 1, n
            deferred_array(i) = deferred_array(i) + 1
        end do
    end subroutine sub1
end module bind_c_array_params

program test_bind_c_array_params
    use bind_c_array_params
    use, intrinsic :: iso_c_binding
    implicit none

    integer(c_int), dimension(5) :: array1 = [1, 2, 3, 4, 5]
    integer(c_int), allocatable :: array2(:)
    integer :: n

    ! Test sub0 with a fixed-size array
    n = size(array1)
    call sub0(array1, n)
    print *, "sub0 result:", array1

    ! Test sub1 with a dynamically allocated array
    allocate(array2(3))
    array2 = [10, 20, 30]
    n = size(array2)
    call sub1(array2, n)
    print *, "sub1 result:", array2

    deallocate(array2)
end program test_bind_c_array_params