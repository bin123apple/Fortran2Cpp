module typeSizes
  implicit none
  public
  integer, parameter ::   OneByteInt = selected_int_kind(2), &
                          TwoByteInt = selected_int_kind(4), &
                         FourByteInt = selected_int_kind(9), &
                        EightByteInt = selected_int_kind(18)

  integer, parameter ::                                          &
                        FourByteReal = selected_real_kind(P =  6, R =  37), &
                       EightByteReal = selected_real_kind(P = 13, R = 307)
contains
  logical function byteSizesOK()
    integer (kind =  OneByteInt) :: One
    integer (kind =  TwoByteInt) :: Two
    integer (kind = FourByteInt) :: Four

    if (bit_size(One) == 8  .and. bit_size(Two) == 16 .and. &
        bit_size(Four) == 32 .and. &
        FourByteReal > 0 .and. EightByteReal > 0 .and. &
        FourByteReal /= EightByteReal) then
      byteSizesOK = .true.
    else
      byteSizesOK = .false.
    end if
  end function byteSizesOK
end module typeSizes

program testTypeSizes
  use typeSizes
  implicit none

  if (byteSizesOK()) then
    print *, "Test passed: byteSizesOK returned .true."
  else
    print *, "Test failed: byteSizesOK returned .false."
  end if
end program testTypeSizes