module m
    implicit none
    type :: t
        procedure(abc), pointer, nopass :: ptr
    end type t
contains
    function abc(arg) result(res)
        character(len=5), target :: arg
        character(len=5), pointer :: res
        res => arg
    end function abc
end module m

program test_m
    use m
    implicit none
    type(t) :: x
    character(len=5) :: str = 'abcde'
    character(len=5), pointer :: strptr

    ! Associate the function pointer
    x%ptr => abc

    ! Use the function pointer
    strptr => x%ptr(str)
    if (strptr /= 'abcde') then
        print *, 'Test 1 Failed'
    else
        print *, 'Test 1 Passed'
    endif

    str = 'fghij'
    strptr => x%ptr(str)
    if (strptr /= 'fghij') then
        print *, 'Test 2 Failed'
    else
        print *, 'Test 2 Passed'
    endif
end program test_m