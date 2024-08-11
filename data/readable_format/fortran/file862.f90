! Combined.f90
module dynamic
  implicit none

contains

  subroutine say
    print *, "Hello, hello..."
  end subroutine say

end module dynamic

program test_dynamic
  use dynamic
  implicit none

  call say()

end program test_dynamic