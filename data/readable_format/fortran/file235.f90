program p
    implicit none
    real, target :: z(3) = 1.0
    real :: res(3)
    real, pointer :: xxx(:)

    ! Your main program code here

    call test_sub()
    call test_double()
    call test_get_var()

contains

    subroutine sub(x, res)
        real, intent(in) :: x(:)
        real, intent(out) :: res(3)
        res = x
    end subroutine sub

    subroutine double(x)
        real :: x(:)
        x = x * 2.0
    end subroutine double

    function get_var() result(ptr)
        real, pointer :: ptr(:)
        ptr => z
    end function get_var

    subroutine test_sub()
        real :: test_res(3)
        real :: expected_res(3) = (/1.0, 1.0, 1.0/)
        real :: input_arr(3) = (/1.0, 1.0, 1.0/)
        call sub(input_arr, test_res)
        if (all(abs(test_res - expected_res) < epsilon(1.0))) then
            print *, "test_sub passed."
        else
            print *, "test_sub failed."
        endif
    end subroutine test_sub

    subroutine test_double()
        real :: test_arr(3) = (/1.0, 2.0, 3.0/)
        call double(test_arr)
        if (all(abs(test_arr - (/2.0, 4.0, 6.0/)) < epsilon(1.0))) then
            print *, "test_double passed."
        else
            print *, "test_double failed."
        endif
    end subroutine test_double

    subroutine test_get_var()
        real, pointer :: ptr(:)
        ptr => get_var()
        if (associated(ptr)) then
            print *, "test_get_var passed."
        else
            print *, "test_get_var failed."
        endif
    end subroutine test_get_var

end program p