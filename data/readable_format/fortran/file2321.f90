program test_a1_d1
    implicit none
    integer :: a(10), b(10)
    integer :: i, nerr, ival, jval

    ! Initialize arrays
    b = -1234
    do i=1,10
       a(i) = i
    end do

    ! Simulate the operation that would have been performed by the second image
    do i=1,7
        b(i) = a(i)
    end do

    ! Error checking as would be done by the first image
    nerr = 0
    do i=1,7
        ival = a(i)
        jval = b(i)
        if (jval /= ival) then
            write(*,*) "b(", i, ")=", jval, " should be ", ival
            nerr = nerr + 1
        end if
    end do

    do i=8,10
        if (b(i) /= -1234) then
            write(*,*) "b(", i, ")=", b(i), " should be -1234"
            nerr = nerr + 1
        end if
    end do

    if (nerr == 0) then
        print *, "result OK"
    else
        print *, "result number of NGs: ", nerr
    end if
end program test_a1_d1