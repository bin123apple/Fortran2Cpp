module z
   character(6) :: a(2) = (/ ('main  ' , i = 1, 2) /)
   character(6) :: b(2) = (/ 'abcd  ' , 'efghij' /)
end module

program y
  use z
  implicit none

  ! Test `a` array
  if (a(1) == 'main  ' .and. a(2) == 'main  ') then
     print *, 'Test for array a passed.'
  else
     print *, 'Test for array a failed.'
     stop
  end if

  ! Test `b` array
  if (b(1) == 'abcd  ' .and. b(2) == 'efghij') then
     print *, 'Test for array b passed.'
  else
     print *, 'Test for array b failed.'
     stop
  end if

end program y