program test_a2_d0
    implicit none
    real :: a2(2,3)
    integer :: nerr, i, j
    real :: val, eps
    integer :: me
    ! Assuming a single image for simplicity
    me = 1
    a2 = 7.77
    eps = 0.00001
    nerr = 0

    ! Mimicking coarray behavior with conditional checks
    if (me == 1) then
        a2(1,2) = 1.22
        a2(2,2) = 2.22
    else if (me == 2) then
        a2(2,2) = 2.23
        a2(2,3) = 2.33
    end if

    do j=1,3
        do i=1,2
            val = 7.77  ! Default value
            if (i==1 .and. j==2 .and. me==1) val=1.22
            if (i==2 .and. j==2 .and. me==1) val=2.22
            if (i==2 .and. j==2 .and. me==2) val=2.23
            if (i==2 .and. j==3 .and. me==2) val=2.33
            if (abs(a2(i,j)-val) > eps) then
                write(*,*) "a2(",i,",",j,")=",a2(i,j)," should be ",val
                nerr = nerr + 1
            end if
        end do
    end do

    if (nerr == 0) then
        write(*,*) "[",me,"] OK"
    else
        write(*,*) "[",me,"] number of NGs: ", nerr
    end if

end program test_a2_d0