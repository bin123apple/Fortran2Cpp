! Define the maxmin subroutine
subroutine maxmin(data, npix, nlin, inval, datmax, datmin, ierr)
  implicit none
  integer, intent(in) :: npix, nlin, inval
  integer, intent(out) :: datmax, datmin, ierr
  integer*2, intent(in) :: data(npix, nlin)
  integer :: datval, line, pixel
  logical :: first
  first = .true.
  do line = 1, nlin
     do pixel = 1, npix
        datval = data(pixel, line)
        if(datval /= inval) then
           if (first) then
              datmax = datval
              datmin = datval
              first = .false.
           else
              datmax = max(datmax, datval)
              datmin = min(datmin, datval)
           end if
        end if
     end do
  end do
  if (first) then
     ierr = 1
     datmin = inval
     datmax = inval
  else
     ierr = 0
  end if
end subroutine maxmin

! Test program for maxmin subroutine
program test_maxmin
  implicit none
  integer, parameter :: npix = 3, nlin = 3
  integer*2 :: data(npix, nlin)
  integer :: datmax, datmin, ierr
  
  ! Initialize the data array
  data = reshape((/1, 2, 3, -1, 5, 6, 7, 8, 9/), shape(data))
  
  ! Call the maxmin subroutine
  call maxmin(data, npix, nlin, -1, datmax, datmin, ierr)
  
  ! Print the results
  print *, "Max: ", datmax
  print *, "Min: ", datmin
  print *, "Error: ", ierr
end program test_maxmin