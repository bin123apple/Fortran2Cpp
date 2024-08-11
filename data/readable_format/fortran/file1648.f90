module NumericKinds
  implicit none

  integer, parameter :: &
       R_SP = selected_real_kind(6, 37), &
       R_DP = selected_real_kind(15, 307), &
       R_QP = selected_real_kind(33, 4931)

  integer, parameter :: RK = R_DP

  integer, parameter :: &
       I1B = selected_int_kind(2), &
       I2B = selected_int_kind(4), &
       I3B = selected_int_kind(9), &
       I4B = selected_int_kind(18)

  integer, parameter :: IK = I3B

  character(len=*), parameter :: R_SP_FMT = "f0.6", &
       R_DP_FMT = "f0.15", R_QP_FMT = "f0.33"

  character(len=*), parameter :: RK_FMT = R_DP_FMT

contains

  elemental subroutine swapRealRK(a, b)
    real(RK), intent(inout) :: a, b
    real(RK) :: tmp
    tmp = a
    a = b
    b = tmp
  end subroutine swapRealRK

  elemental subroutine swapIntIK(a, b)
    integer(IK), intent(inout) :: a, b
    integer(IK) :: tmp
    tmp = a
    a = b
    b = tmp
  end subroutine swapIntIK

end module NumericKinds

program testNumericKinds
  use NumericKinds
  implicit none

  real(RK) :: realA = 1.0_RK, realB = 2.0_RK
  integer(IK) :: intA = 1, intB = 2

  ! Test swapping real numbers
  call swapRealRK(realA, realB)
  if (realA == 2.0_RK .and. realB == 1.0_RK) then
    print *, "Real swap test passed."
  else
    print *, "Real swap test failed."
  end if

  ! Test swapping integer numbers
  call swapIntIK(intA, intB)
  if (intA == 2 .and. intB == 1) then
    print *, "Integer swap test passed."
  else
    print *, "Integer swap test failed."
  end if

end program testNumericKinds