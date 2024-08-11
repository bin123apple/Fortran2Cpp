module basechange_mod
  implicit none
contains
  subroutine basechange_d(d)
    double precision, intent(in) :: d
    print *, 'basechange_d with input:', d
  end subroutine basechange_d

  subroutine basechange_c(c)
    complex, intent(in) :: c
    print *, 'basechange_c with input:', c
  end subroutine basechange_c

  subroutine basechange_z(z)
    complex(kind=16), intent(in) :: z
    print *, 'basechange_z with input:', z
  end subroutine basechange_z
end module basechange_mod

program test_basechange
  use basechange_mod
  implicit none
  ! Declare variables
  complex :: c  ! Default kind, usually corresponds to COMPLEX(4) in many compilers
  complex(kind=16) :: z

  ! Test double precision
  call basechange_d(2.0d0)

  ! Test complex number
  c = cmplx(2.0, 3.0)  ! Create a single-precision complex number
  call basechange_c(c)

  ! Test double-complex number
  z = cmplx(4.0d0, 5.0d0, kind=16)  ! Create a double-precision complex number
  call basechange_z(z)
end program test_basechange