program test_main
    implicit none
    call test_subroutine
end program test_main

subroutine test_subroutine
    implicit none
    print *, 'Test passed.'
end subroutine test_subroutine