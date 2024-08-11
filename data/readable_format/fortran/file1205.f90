program main
    implicit none
    integer :: a, b, d

    ! Initialize variables
    a = 2
    b = 3
    d = 0

    ! Call the subroutine
    call test(a, b, d)

    ! Print the result to verify it worked
    print *, "After calling test, d = ", d

contains

    subroutine test(a, b, d)
        integer, intent(in) :: a, b
        integer, intent(out) :: d
        
        ! Perform a simple operation, e.g., sum a and b
        d = a + b
    end subroutine test

end program main