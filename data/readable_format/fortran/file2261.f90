module protmod
  implicit none
  integer, protected :: a
  integer, protected, target :: at
  integer, protected, pointer :: ap

contains
  subroutine set_values()
    a = 10
    at = 20
    ap => at
    at = 30  ! Notice that both 'at' and 'ap' will reflect this change
  end subroutine set_values

  subroutine print_values()
    print *, 'Value of a:', a
    print *, 'Value of at:', at
    print *, 'Value of ap (points to at):', ap
  end subroutine print_values
end module protmod

program test_protmod
  use protmod
  call set_values()
  call print_values()
end program test_protmod