module digit_module
  implicit none
  contains

  ! Function to parse a floating-point number from a string
  real(kind=kind(0.0d0)) function digit(string, istart) 
    implicit none
    integer, intent(in) :: istart
    character(len=*), intent(in) :: string
    integer :: i0, i9, ineg, ipos, idot, ispc, l, idig, i, n, j
    real(kind=kind(0.0d0)) :: c1, c2, deciml
    logical :: sign

    ! Character code assignments
    i0 = ichar('0')
    i9 = ichar('9')
    ineg = ichar('-')
    ipos = ichar('+')
    idot = ichar('.')
    ispc = ichar(' ')
    
    ! Initialization
    c1 = 0.0d0
    c2 = 0.0d0
    sign = .TRUE.
    l = len(string)
    idig = 0

    ! Main loop to parse before decimal point
    do i = istart, l
      n = ichar(string(i:i))
      if (n >= i0 .and. n <= i9) then
        idig = idig + 1
        c1 = c1 * 10.0d0 + n - i0
      else if (n == ineg .or. n == ipos .or. n == ispc) then
        if (n == ineg) sign = .FALSE.
      else if (n == idot) then
        exit
      else
        exit
      endif
    end do

    ! Parsing after decimal point
    deciml = 1.0d0
    do j = i + 1, l
      n = ichar(string(j:j))
      if (n >= i0 .and. n <= i9) then
        deciml = deciml / 10.0d0
        c2 = c2 + (n - i0) * deciml
      else if (n /= ispc) then
        exit
      endif
    end do

    ! Combine parts and apply sign
    digit = c1 + c2
    if (.not. sign) digit = -digit
  end function digit
end module digit_module


program test_digit
  use digit_module
  implicit none

  ! Example usage of digit function
  real(kind=kind(0.0d0)) :: result
  character(len=100) :: testString

  ! Test cases
  testString = '  -123.4567moretext'
  result = digit(testString, 1)
  print *, "Parsed number: ", result

end program test_digit