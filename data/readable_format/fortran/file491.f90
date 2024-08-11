module Foo_mod

    implicit none
    private

    public :: someFunction
    public :: Foo

    type Foo
    end type Foo

contains

    function someFunction(inParam, outParam, inOutParam) result(returnValue)
        real, intent(in) :: inParam
        real, intent(out) :: outParam
        real, intent(inout) :: inOutParam
        real :: returnValue
        
        ! Assuming some operations here since the original code doesn't specify them
        outParam = inParam * 2.0
        inOutParam = inOutParam + 1.0
        returnValue = outParam + inOutParam
        
    end function someFunction

end module Foo_mod

program testFoo
    use Foo_mod
    implicit none

    real :: inParam
    real :: inOutParam
    real :: outParam
    real :: result

    ! Initialize variables
    inParam = 5.0
    inOutParam = 3.0

    ! Call the function
    result = someFunction(inParam, outParam, inOutParam)

    ! Output the results
    print *, "Result: ", result
    print *, "InOutParam: ", inOutParam
    print *, "OutParam: ", outParam

end program testFoo