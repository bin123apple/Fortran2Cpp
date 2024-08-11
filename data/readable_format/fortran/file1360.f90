program test_a2_d0
    implicit none
    real :: a2(2,3)
    integer :: nerr, i, j
    real :: eps, val
    integer :: me

    eps = 0.00001
    nerr = 0
    me = 1 ! Simulated rank for testing in a non-parallel context

    ! Initialize a2
    a2 = 7.77

    ! Simulated conditional modifications
    if (me == 1) then
       a2(1,2) = 1.22
    else if (me == 2) then
       a2(2,3) = 2.33
    end if

    ! Test conditions
    do j = 1, 3
       do i = 1, 2
          if (i == 1 .and. j == 2 .and. me == 1) then
             val = 1.22
          else if (i == 2 .and. j == 3 .and. me == 2) then
             val = 2.33
          else
             val = 7.77
          end if

          if (abs(a2(i,j) - val) > eps) then
             print *, "Test Failed: a2(", i, ",", j, ")=", a2(i,j), " should be ", val
             nerr = nerr + 1
          end if
       end do
    end do

    if (nerr == 0) then
       print *, "Fortran Test Passed"
    else
       print *, "Fortran Test Failed, errors: ", nerr
    end if
end program