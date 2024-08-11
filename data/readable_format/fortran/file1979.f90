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
    subroutine check_values(my_type, expected_i, expected_nested_c_address, &
         expected_array_1, expected_array_2, expected_array_3, &
         expected_c_address, expected_j) bind(c)
        type(my_c_type_1), intent(in) :: my_type
        integer(c_int), intent(in), value :: expected_i
        type(c_ptr), intent(in), value :: expected_nested_c_address
        integer(c_int), intent(in), value :: expected_array_1, expected_array_2, expected_array_3
        type(c_ptr), intent(in), value :: expected_c_address
        integer(c_int), intent(in), value :: expected_j

        if (my_type%my_nested_type%i /= expected_i) call abort()
        if (my_type%my_nested_type%array(1) /= expected_array_1) call abort()
        if (my_type%my_nested_type%array(2) /= expected_array_2) call abort()
        if (my_type%my_nested_type%array(3) /= expected_array_3) call abort()
        if (my_type%j /= expected_j) call abort()

        print *, "Fortran test passed successfully."
    end subroutine check_values
end module bind_c_dts_2

program test_program
    use bind_c_dts_2
    use, intrinsic :: iso_c_binding, only: c_null_ptr
    implicit none

    type(my_c_type_1) :: test_instance
    integer(c_int) :: expected_values(3)
    expected_values = [1, 2, 3]

    test_instance%my_nested_type%i = 1
    test_instance%my_nested_type%nested_c_address = c_null_ptr
    test_instance%my_nested_type%array = expected_values
    test_instance%c_address = c_null_ptr
    test_instance%j = 4

    call check_values(test_instance, 1, c_null_ptr, 1, 2, 3, c_null_ptr, 4)
end program test_program