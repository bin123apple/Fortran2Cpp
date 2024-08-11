module mytypes
   implicit none
 contains
   pure integer function get_i ()
     get_i = 13
   end function
end module

program testMyTypes
  use mytypes
  implicit none
  integer :: result
  
  ! Testing get_i function
  result = get_i()
  if (result == 13) then
    print *, "Test get_i passed."
  else
    print *, "Test get_i failed."
  end if
end program testMyTypes