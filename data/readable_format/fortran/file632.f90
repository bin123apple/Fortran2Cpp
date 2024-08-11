program test_i8_bit_hi1
  use iso_fortran_env, only: int64
  implicit none
  integer(int64) :: result

  ! Test 1: Test with 0, expecting 0
  result = i8_bit_hi1(0_int64)
  if (result /= 0_int64) then
    write(*,*) 'Test 1 failed: Expected 0, got ', result
  else
    write(*,*) 'Test 1 passed.'
  end if

  ! Test 2: Test with 1, expecting 1
  result = i8_bit_hi1(1_int64)
  if (result /= 1_int64) then
    write(*,*) 'Test 2 failed: Expected 1, got ', result
  else
    write(*,*) 'Test 2 passed.'
  end if

  ! Test 3: Test with 2, expecting 2
  result = i8_bit_hi1(2_int64)
  if (result /= 2_int64) then
    write(*,*) 'Test 3 failed: Expected 2, got ', result
  else
    write(*,*) 'Test 3 passed.'
  end if

  ! Test 4: Test with 1023 (all bits set up to bit 10), expecting 10
  result = i8_bit_hi1(1023_int64)
  if (result /= 10_int64) then
    write(*,*) 'Test 4 failed: Expected 10, got ', result
  else
    write(*,*) 'Test 4 passed.'
  end if

contains

  function i8_bit_hi1(n) result(bit)
    integer(int64), intent(in) :: n
    integer(int64) :: bit
    integer(int64) :: i

    i = n
    bit = 0

    do while (i > 0)
      bit = bit + 1
      i = i / 2
    end do
  end function i8_bit_hi1

end program test_i8_bit_hi1