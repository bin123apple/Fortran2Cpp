! Define the module with an interface for refer_sub
module refer_I
  implicit none
  interface
    subroutine refer_sub()
    end subroutine refer_sub
  end interface
end module refer_I

! Implement the refer_sub subroutine
subroutine refer_sub()
  print *, "Hello from refer_sub"
end subroutine refer_sub

! Main program to test the refer_sub subroutine
program test_refer
  use refer_I
  call refer_sub()
end program test_refer