module typeSizes
  implicit none
  integer, parameter :: OneByteInt = selected_int_kind(2)
  integer, parameter :: TwoByteInt = selected_int_kind(4)
  integer, parameter :: FourByteInt = selected_int_kind(9)
  integer, parameter :: EightByteInt = selected_int_kind(18)

  integer, parameter :: FourByteReal = selected_real_kind(P =  6, R =  37)
  integer, parameter :: EightByteReal = selected_real_kind(P = 15, R = 307)

contains

  logical function byteSizesOK()
    integer (kind =  OneByteInt)  :: One   = 1
    integer (kind =  TwoByteInt)  :: Two   = 2
    integer (kind = FourByteInt)  :: Four  = 4
    integer (kind = EightByteInt) :: Eight = 8

    byteSizesOK = .true.

    if (bit_size(One) /= 8) byteSizesOK = .false.
    if (bit_size(Two) /= 16) byteSizesOK = .false.
    if (bit_size(Four) /= 32) byteSizesOK = .false.
    if (bit_size(Eight) /= 64) byteSizesOK = .false.
    if (.not. (FourByteReal > 0 .and. EightByteReal > 0 .and. FourByteReal /= EightByteReal)) then
      byteSizesOK = .false.
    endif
  end function byteSizesOK

end module typeSizes

program testTypeSizes
  use typeSizes
  implicit none

  if (byteSizesOK()) then
    print *, "Byte sizes and type requirements are OK."
  else
    print *, "Byte sizes or type requirements are not met."
  end if

end program testTypeSizes