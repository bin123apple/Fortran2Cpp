module test_module
    implicit none
    type :: MyType
        integer, allocatable :: data(:)
        integer :: currentSize
    contains
        procedure :: resetArray
    end type MyType

contains

    subroutine resetArray(this)
        class(MyType), intent(inout) :: this
        if (allocated(this%data)) deallocate(this%data)
        this%currentSize = 0
    end subroutine resetArray

end module test_module

program test_program
    use test_module
    implicit none
    type(MyType) :: testObj

    ! Test 1: Check if `resetArray` correctly deallocates and resets `currentSize`
    allocate(testObj%data(10))
    testObj%data = 1
    testObj%currentSize = 10

    call testObj%resetArray()

    if (.not. allocated(testObj%data) .and. testObj%currentSize == 0) then
        print *, "Test 1 Passed: Array deallocated and currentSize reset."
    else
        print *, "Test 1 Failed."
    end if

end program test_program