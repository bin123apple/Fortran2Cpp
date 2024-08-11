module pr32601
    use, intrinsic :: iso_c_binding, only: c_int
    implicit none
contains
    function get_ptr() result(ptr)
        integer(c_int), pointer :: ptr
        integer(c_int), target :: x
        ptr => x
    end function get_ptr
end module pr32601

program test_pr32601
    use iso_c_binding, only: c_ptr, c_null_ptr, c_associated, c_loc
    use pr32601
    implicit none

    type(c_ptr) :: t
    type(c_ptr) :: ptr_from_func
    integer :: i
    integer(c_int), pointer :: int_ptr

    ! Test 1: Check if t is a null pointer
    t = c_null_ptr
    if (c_associated(t)) then
        print *, "Test 1 Failed: t is not a null pointer."
    else
        print *, "Test 1 Passed: t is a null pointer."
    endif

    ! Test 2: Check pointer from get_ptr function
    int_ptr => get_ptr()
    ptr_from_func = c_loc(int_ptr)
    if (.not. c_associated(ptr_from_func)) then
        print *, "Test 2 Failed: ptr_from_func is a null pointer."
    else
        print *, "Test 2 Passed: ptr_from_func is not a null pointer."
    endif

    ! Optional: Demonstrating the usage of the pointer
    ! Assigning value to the target of int_ptr and printing
    int_ptr = 5
    print *, "Value pointed to by int_ptr:", int_ptr
end program test_pr32601