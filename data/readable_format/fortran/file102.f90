subroutine test(proc)
    implicit none
    interface
        real function proc(x)
            real, intent(in) :: x
        end function proc
    end interface
    real a, b, c

    a = 1.0
    b = sin(a)
    c = proc(a)

    if (abs(b - c) > 0.001) call abort
end subroutine

real function customFunc(x)
    real, intent(in) :: x
    customFunc = 2.0 * sin(x)  ! This should cause an abort if used
end function customFunc

program test_program
    implicit none
    external test, customFunc
    intrinsic sin

    print *, "Testing with sin"
    call test(sin)
    print *, "Test with sin completed successfully"

    print *, "Testing with customFunc"
    call test(customFunc)  ! This should cause an abort
    print *, "Test with customFunc completed successfully"
end program