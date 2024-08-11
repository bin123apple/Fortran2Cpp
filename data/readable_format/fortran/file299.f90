program test_f
implicit none

call f()

contains

subroutine f()
block
  integer :: k
end block
end subroutine f

end program test_f