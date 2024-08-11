module good
   implicit none
   type default_initialization
      integer :: x = 42
   end type default_initialization
   type (default_initialization) t
end module good

use good
if (t%x /= 42) call abort()
t%x = 0
if (t%x /= 0) call abort()
end