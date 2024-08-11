module where_logic
    implicit none
contains
    subroutine test_where_15()
        integer :: a(5)
        integer :: b(5)
        integer :: expected_b(5)
        logical :: test_passed

        a = (/1, 2, 3, 4, 5/)
        b = (/0, 0, 0, 0, 0/)
        where (a == 1)
        elsewhere
            b = 2
        end where

        expected_b = (/0, 2, 2, 2, 2/)

        test_passed = all(b == expected_b)
        if (.not. test_passed) then
            print *, 'Test failed: Arrays do not match.'
            stop 1
        else
            print *, 'Test passed.'
        endif
    end subroutine test_where_15
end module where_logic

program test_program
    use where_logic
    call test_where_15()
end program test_program