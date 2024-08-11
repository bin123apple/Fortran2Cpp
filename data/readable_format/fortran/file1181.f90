program test_leap_year
  implicit none

  print *, 'Testing year 2000:', isaleap(2000) ! Expected: 1
  print *, 'Testing year 1900:', isaleap(1900) ! Expected: 0
  print *, 'Testing year 2016:', isaleap(2016) ! Expected: 1
  print *, 'Testing year 2019:', isaleap(2019) ! Expected: 0

contains

  integer function isaleap(year)
    implicit none
    integer year

    if ((mod(year,4) == 0 .and. mod(year,100) /= 0) .or. mod(year,400) == 0) then
      isaleap = 1
    else
      isaleap = 0
    endif
  end function isaleap

end program test_leap_year