program nb_defuse1_test

    implicit none
    integer, parameter :: dp = kind(1.0d0)
    complex(dp) :: a(120,120), b(120,120), c(120,120)
    integer :: nerr, i, j, me
    integer, parameter :: me_test = 3

    ! Initialize arrays
    do j = 1, 120
       do i = 1, 120
          a(i,j) = cmplx(dble(i), dble(j), dp)
       end do
    end do
    b = cmplx(4.0_dp, 4.0_dp, dp)
    c = cmplx(1.0_dp, 1.0_dp, dp)

    ! Simulate operations for image 3
    if (me_test == 3) then
       b(41:80,:) = a(41:80,:) * 2.0_dp
       c(:,41:80) = b(:,41:80)
    endif

    ! Check for errors
    nerr = 0
    do j = 1, 120
       do i = 1, 120
          if (j >= 41 .and. j <= 80) then
             if (i >= 41 .and. i <= 80) then
                if (c(i,j) /= a(i,j) * 2.0_dp) then
                   nerr = nerr + 1
                end if
             else
                if (c(i,j) /= cmplx(4.0_dp, 4.0_dp, dp)) then
                   nerr = nerr + 1
                end if
             end if
          else
             if (c(i,j) /= cmplx(1.0_dp, 1.0_dp, dp)) then
                nerr = nerr + 1
             end if
          end if
       end do
    end do

    ! Output result based on the error check
    if (nerr == 0) then 
       print *, "Test result for image", me_test, ": OK"
    else
       print *, "Test result for image", me_test, ": number of errors:", nerr
    end if

end program nb_defuse1_test