module bind_c_dts_2
    use, intrinsic :: iso_c_binding
    implicit none

    type, bind(c) :: my_c_type_0
        integer(c_int) :: i
        type(c_ptr) :: nested_c_address
        integer(c_int) :: array(3)
    end type my_c_type_0

    type, bind(c) :: my_c_type_1
        type(my_c_type_0) :: my_nested_type
        type(c_ptr) :: c_address
        integer(c_int) :: j
    end type my_c_type_1

contains
    subroutine sub0(my_type, expected_i, expected_nested_c_address, &
            expected_array_1, expected_array_2, expected_array_3, &
            expected_c_address, expected_j) bind(c)
        type(my_c_type_1) :: my_type
        integer(c_int), value :: expected_i
        type(c_ptr), value :: expected_nested_c_address
        integer(c_int), value :: expected_array_1
        integer(c_int), value :: expected_array_2
        integer(c_int), value :: expected_array_3
        type(c_ptr), value :: expected_c_address
        integer(c_int), value :: expected_j

        if (my_type%my_nested_type%i .ne. expected_i) then
            call abort()
        end if

        if (.not. c_associated(my_type%my_nested_type%nested_c_address, &
                expected_nested_c_address)) then
            call abort()
        end if

        if (my_type%my_nested_type%array(1) .ne. expected_array_1) then
            call abort()
        end if

        if (my_type%my_nested_type%array(2) .ne. expected_array_2) then
            call abort()
        end if

        if (my_type%my_nested_type%array(3) .ne. expected_array_3) then
            call abort()
        end if

        if (.not. c_associated(my_type%c_address, expected_c_address)) then
            call abort()
        end if

        if (my_type%j .ne. expected_j) then
            call abort()
        end if
    end subroutine sub0
end module bind_c_dts_2

program test_bind_c_dts_2
    use bind_c_dts_2
    implicit none

    type(my_c_type_1), target :: test_type
    type(c_ptr) :: dummy_c_ptr
    integer, target :: dummy_target

    ! Initialize the test data
    test_type%my_nested_type%i = 42
    dummy_c_ptr = c_loc(dummy_target)
    test_type%my_nested_type%nested_c_address = dummy_c_ptr
    test_type%my_nested_type%array = [1, 2, 3]
    test_type%c_address = dummy_c_ptr
    test_type%j = 99

    ! Call the subroutine with the expected values
    call sub0(test_type, 42, dummy_c_ptr, 1, 2, 3, dummy_c_ptr, 99)

    print *, "Fortran Test Passed"
end program test_bind_c_dts_2