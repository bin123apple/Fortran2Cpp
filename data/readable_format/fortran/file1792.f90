program exampleTest
    implicit none
    character (:), pointer :: ptr => NULL()
    character (6), target :: tgt = 'lmnopq'
    ptr => tgt
    call test(ptr)

contains

    subroutine test(ptr)
        character(:), pointer :: ptr
        if (len(ptr) .eq. 6 .and. trim(ptr) .eq. 'lmnopq') then
            print *, "Test Passed"
        else
            print *, "Test Failed"
        endif
    end subroutine test

end program exampleTest