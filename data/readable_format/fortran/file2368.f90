module types_mod
  implicit none
  type :: t
  end type t
end module types_mod

program test_program
  use types_mod
  implicit none

  call one()
  call two()
  call three()
  call four()

contains

  subroutine one()
    use types_mod
    type(t), target :: p1
    type(t), pointer :: p2
    p2 => p1
    print *, "one: p2 points to p1"
  end subroutine one

  subroutine two()
    use types_mod
    type(t), allocatable, target :: p1 ! Marked as target
    type(t), pointer :: p2

    allocate(p1)
    p2 => p1
    print *, "two: p2 points to allocated p1"
    deallocate(p1)
  end subroutine two

  subroutine three()
    use types_mod
    type(t), allocatable, target :: p1 ! Marked as target
    type(t), pointer :: p2

    allocate(p1)
    p2 => p1
    print *, "three: p2 points to allocated p1"
    deallocate(p1)
  end subroutine three

  subroutine four()
    use types_mod
    type(t), pointer :: p1
    type(t), pointer :: p2

    allocate(p1)
    p2 => p1
    print *, "four: p2 points to allocated p1"
    deallocate(p1)
  end subroutine four

end program test_program