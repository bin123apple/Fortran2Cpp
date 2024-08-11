module bind_c_array_params
    use, intrinsic :: iso_c_binding
    implicit none

contains

    subroutine sub0(assumed_array) bind(c)
        integer(c_int), dimension(:), intent(in) :: assumed_array
        print *, "Assumed-size array elements:"
        print *, assumed_array
    end subroutine sub0

    subroutine sub1(deferred_array) bind(c)
        integer(c_int), pointer, intent(in) :: deferred_array(:)
        print *, "Deferred-size array elements:"
        print *, deferred_array
    end subroutine sub1

end module bind_c_array_params

program test_bind_c_array_params
    use bind_c_array_params
    use, intrinsic :: iso_c_binding
    implicit none

    integer(c_int) :: assumed_array(5) = [1, 2, 3, 4, 5]
    integer(c_int), pointer :: deferred_array(:)
    integer(c_int) :: size

    ! Test for sub0: Assuming size is known
    call sub0(assumed_array)

    ! Test for sub1: Deferred size array
    size = 3
    allocate(deferred_array(size))
    deferred_array = [10, 20, 30]
    call sub1(deferred_array)
    deallocate(deferred_array)

end program test_bind_c_array_params