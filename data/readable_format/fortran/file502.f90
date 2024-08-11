program main
  implicit none
  integer :: me, i, nerr, ival
  integer, dimension(10) :: aa

  ! Assuming a value for 'me' since we're not in a parallel context
  me = 1
  nerr = 0

  ! Fill the array with values based on the 'me' variable
  do i=1,10
     if (me == 3) then
        aa(i) = 10 - i
     else
        aa(i) = -i * 100
     end if
  end do

  ! Check the array against expected values
  do i=1,10
     if (me == 1 .and. i == 3) then
        ival = 555
     else if (me == 1 .and. i == 4) then
        ival = 666
     else if (me == 3) then
        ival = 10 - i
     else
        ival = -i * 100
     end if

     if (aa(i) /= ival) then
        print *, "Mismatch at i=", i, "with aa(i)=", aa(i), "and ival=", ival
        nerr = nerr + 1
     endif
  end do

  ! Reporting error count
  if (nerr == 0) then
    print *, "OK"
  else
    print *, "number of NGs: ", nerr
  end if

end program main