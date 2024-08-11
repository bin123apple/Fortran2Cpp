module my_functions
    implicit none
contains
    ! Identity function: lambda x:A. x
    function identity(x) result(res)
        integer, intent(in) :: x
        integer :: res
        res = x
    end function identity

    ! Increment function
    function increment(x) result(res)
        integer, intent(in) :: x
        integer :: res
        res = x + 1
    end function increment
end module my_functions

program test
    use my_functions
    implicit none

    ! Test identity function
    call test_identity()

    ! Test higher-order function with increment
    call test_higher_order(increment)  ! Passing 'increment' function as argument

contains
    subroutine test_identity()
        integer :: result
        result = identity(42)
        if (result == 42) then
            print *, "Identity function test passed."
        else
            print *, "Identity function test failed."
        end if
    end subroutine test_identity

    subroutine test_higher_order(func)
        interface
            function func(x)
                integer, intent(in) :: x
                integer :: func
            end function func
        end interface
        integer :: result
        result = func(41)  ! Using the passed function 'func', which is 'increment' in this case
        if (result == 42) then
            print *, "Higher-order function test passed."
        else
            print *, "Higher-order function test failed."
        end if
    end subroutine test_higher_order

end program test