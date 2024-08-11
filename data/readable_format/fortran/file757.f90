module tanh_module
    implicit none
    contains

    ! Function to be tested
    elemental function specific__tanh_r4 (parm) result(res)
        real (kind=4), intent (in) :: parm
        real (kind=4) :: res

        res = tanh (parm)
    end function specific__tanh_r4
end module tanh_module

program test_tanh
    use tanh_module
    implicit none

    real(kind=4) :: test_val
    real(kind=4) :: result

    ! Test cases
    test_val = 0.0
    result = specific__tanh_r4(test_val)
    print *, "tanh(", test_val, ") = ", result

    test_val = 1.0
    result = specific__tanh_r4(test_val)
    print *, "tanh(", test_val, ") = ", result

    test_val = -1.0
    result = specific__tanh_r4(test_val)
    print *, "tanh(", test_val, ") = ", result
end program test_tanh