module tensor_recursive
  implicit none

  type :: tens_signature_t
  contains
    final :: tens_signature_dtor
  end type

  type :: tens_header_t
    type(tens_signature_t) :: signature
  contains
    final :: tens_header_dtor
  end type

contains

  subroutine tens_signature_dtor(this)
    type(tens_signature_t) :: this
    print *, "tens_signature_t destructor called"
  end subroutine

  subroutine tens_header_dtor(this)
    type(tens_header_t) :: this
    print *, "tens_header_t destructor called"
  end subroutine

end module tensor_recursive

program test_destructors
  use tensor_recursive
  implicit none

  type(tens_header_t) :: header

  print *, "Creating and destroying a tens_header_t object"
end program test_destructors