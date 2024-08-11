program main
  implicit none

contains

  ! Procedure valid from test1
  subroutine valid (lhs,rhs)
    integer, intent(out) ::  lhs
    integer, intent(in) :: rhs(:)
    lhs = rhs(1) 
  end subroutine valid

  ! Procedure valid2 from test1
  subroutine valid2 (lhs,rhs)
    integer, intent(out) ::  lhs(:)
    integer, intent(in) :: rhs(:,:)
    lhs(:) = rhs(:,1) 
  end subroutine valid2

  ! Procedure invalid from test2
  subroutine invalid (lhs,rhs)
    integer, intent(out) ::  lhs
    integer, intent(in) :: rhs
    lhs = rhs
  end subroutine invalid

  ! Procedure invalid2 from test3
  subroutine invalid2 (lhs,rhs)
    integer, intent(out) ::  lhs(:)
    integer, intent(in) :: rhs
    lhs(:) = rhs
  end subroutine invalid2

  ! Procedure invalid3 from test4
  subroutine invalid3 (lhs,rhs)
    integer, intent(out) ::  lhs(:)
    integer, intent(in) :: rhs(:)
    lhs(:) = rhs(:)
  end subroutine invalid3

end program main