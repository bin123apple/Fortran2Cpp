module A
  implicit none
  type A_type
    real :: comp
  end type A_type
end module A

module B
  use A, only: A_type
  implicit none
  type(A_type) :: B_var
end module B

program C
  use B, only: B_var
  use A, only: A_type
  implicit none
  type(A_type) :: A_var

  ! Example usage: setting and printing values
  B_var%comp = 5.0
  A_var%comp = 10.0

  print *, "B_var%comp = ", B_var%comp
  print *, "A_var%comp = ", A_var%comp

end program C