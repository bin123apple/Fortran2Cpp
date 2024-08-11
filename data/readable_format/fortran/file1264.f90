program test_t
    implicit none
    integer::i(2)
    integer,parameter::j=1
    i(1)=1
    i(j+1)=2
    call test_i(i)
contains
    subroutine test_i(i)
        integer, intent(in) :: i(2)
        if (i(1) .eq. 1) then
            print *, "Test 1 passed."
        else
            print *, "Test 1 failed."
        endif
        if (i(2) .eq. 2) then
            print *, "Test 2 passed."
        else
            print *, "Test 2 failed."
        endif
    end subroutine test_i
end program test_t