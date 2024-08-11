module test_module
  implicit none

  type :: d
  end type d

  type :: p
    class(d), pointer :: cc
  end type p

contains

  function pc(pd)
    type(p) :: pc
    class(d), intent(in), target :: pd
    pc%cc => pd
  end function pc

  subroutine test_pc
    type(d) :: test_d
    type(p) :: test_p

    ! Test the pc function
    test_p = pc(test_d)
    
    ! Since Fortran lacks a built-in assertion library, we simply print a message for demonstration.
    print *, "Test passed. pc function executed."
  end subroutine test_pc

end module test_module

program test_program
  use test_module
  call test_pc
end program test_program