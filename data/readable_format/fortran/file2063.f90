program test_program
    implicit none
    integer :: test_result

    test_result = test()
    print *, "Test Result: ", test_result
contains

    integer function test()
        integer :: i
        logical :: l

        l = .false.
        i = -1
        if (l) then
            if (i /= 0) then
                goto 999
            else
                goto 999
            endif
        else
            goto 999
        endif

        l = .true.
        if (l) then
            if (i /= 0) then
                goto 10
            else
                goto 999
            endif
        else
            goto 999
        endif

10      i = 0
        if (l) then
            if (i /= 0) then
                goto 999
            else
                goto 20
            endif
        else
            goto 999
        endif

20      i = 1
        if (l) then
            if (i /= 0) then
                goto 999
            else
                goto 30
            endif
        else
            goto 999
        endif

        goto 999

999     test = -1
        return
30      test = 0
    end function test

end program test_program