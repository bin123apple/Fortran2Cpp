subroutine foo(a, n)
    integer, intent(in) :: n
    character(len=n+5), intent(inout) :: a
    ! Fill the string with 'x'. Adjust this as per actual requirements
    a = REPEAT('x', n+5)
end subroutine foo

program testFoo
    implicit none
    character(len=:), allocatable :: testString
    integer :: n

    ! Test case 1
    n = 10
    allocate(character(len=n+5) :: testString)
    call foo(testString, n)
    print *, 'Test 1, Length:', len(testString), 'Expected:', n+5, 'Result:', testString

end program testFoo