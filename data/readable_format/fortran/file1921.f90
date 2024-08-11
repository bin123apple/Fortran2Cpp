program testProgram
    implicit none
    call runTests()
contains

    subroutine test(a)
        character(len=*) :: a
        a = 'Sample#2'
    end subroutine test

    subroutine runTests()
        character, pointer :: ptr(:)
        character(8) :: a
        logical :: testPassed

        ! Test 1: Check the initial transfer and comparison
        allocate(ptr(9))
        ptr = transfer('Sample#0'//achar(0), ptr)
        testPassed = all(ptr == ['S', 'a', 'm', 'p', 'l', 'e', '#', '0', achar(0)])
        if (.not. testPassed) then
            print *, "Test 1 Failed"
            stop 1
        else
            print *, "Test 1 Passed"
        end if

        ! Test 2: Check the subroutine call and string modification
        call test(a)
        testPassed = (a == 'Sample#2')
        if (.not. testPassed) then
            print *, "Test 2 Failed"
            stop 2
        else
            print *, "Test 2 Passed"
        end if
    end subroutine runTests

end program testProgram