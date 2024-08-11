module D

contains

subroutine f_d()
  write (6,*) "f_d()"
end subroutine f_d

end module D

program test
  use D
  call f_d()
end program test