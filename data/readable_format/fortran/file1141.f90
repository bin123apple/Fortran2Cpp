module halton_sequence
  implicit none
contains
  ! Function to get the nth value of a Halton sequence with a given base
  function get_halton(index, base) result(value)
    integer, intent(in) :: index, base
    real :: value
    integer :: n, d
    value = 0.0
    n = index
    d = 1
    do while (n > 0)
      d = d * base
      value = value + mod(n, base) / real(d)
      n = n / base
    end do
  end function get_halton
end module halton_sequence

program test_halton_sequence
  use halton_sequence
  implicit none
  integer :: n
  real, dimension(5) :: expected_values = [0.5, 0.25, 0.75, 0.125, 0.625]
  real :: value
  
  ! Testing the Halton sequence generation for the first 5 values with base 2
  do n = 1, 5
    value = get_halton(n, 2)
    if (abs(value - expected_values(n)) > 1e-5) then
      print *, "Test failed at n =", n, "Expected:", expected_values(n), "Got:", value
      stop
    end if
  end do
  
  print *, "All tests passed."
end program test_halton_sequence