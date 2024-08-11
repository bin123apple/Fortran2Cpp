module bit_utils
  implicit none
contains
  ! Function to compute the highest bit set
  integer(kind=4) function i4_bit_hi1(n)
    integer(kind=4), intent(in) :: n
    integer(kind=4) :: i, bit
    i = n
    bit = 0
    do
      if (i <= 0) then
        exit
      end if
      bit = bit + 1
      i = i / 2
    end do
    i4_bit_hi1 = bit
  end function i4_bit_hi1
end module bit_utils

program test_bit_hi1
  use bit_utils
  implicit none
  integer(kind=4) :: result
  integer(kind=4) :: test_vals(5) = (/0, 1, 2, 3, 1024/)
  integer :: i

  ! Test the function with different values
  do i = 1, 5
     result = i4_bit_hi1(test_vals(i))
     print *, "i4_bit_hi1(", test_vals(i), ") = ", result
  end do
end program test_bit_hi1