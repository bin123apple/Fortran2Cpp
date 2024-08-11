program main

  real a2(16,16)
  logical :: pass = .true.

  do j=1, 16
    do i=1, 16
      a2(i,j) = 0.
    end do
  end do

  ! Check if all elements are zero
  do j=1, 16
    do i=1, 16
      if (a2(i,j) /= 0.) then
        pass = .false.
      end if
    end do
  end do

  if (pass) then
    write(*,*) "PASS"
  else
    write(*,*) "FAIL"
  end if

end program main