program test_func0
    use, intrinsic :: iso_c_binding, only: c_ptr, c_null_ptr, c_associated
    implicit none

    interface
        function func0() bind(C)
            import :: c_ptr
            type(c_ptr) :: func0
        end function func0
    end interface

    type(c_ptr) :: result

    result = func0()
    if (.not. c_associated(result)) then
        print *, "Test passed: func0() returned a null pointer."
    else
        print *, "Test failed: func0() did not return a null pointer."
    endif
end program test_func0

function func0() bind(C)
    use, intrinsic :: iso_c_binding, only: c_ptr, c_null_ptr
    type(c_ptr) :: func0
    func0 = c_null_ptr
end function func0