program test_sctovec
  implicit none
  real(8) :: tp(2)
  real(8) :: v(3)
  real(8) :: expected_v(3)
  real(8) :: tolerance

  ! Set tolerance for floating point comparison
  tolerance = 1.0d-10

  ! Test Case
  tp(1) = 1.0d0  ! Example input
  tp(2) = 0.5d0
  call sctovec(tp, v)  ! Call the subroutine

  ! Expected results
  expected_v(1) = sin(tp(1)) * cos(tp(2))
  expected_v(2) = sin(tp(1)) * sin(tp(2))
  expected_v(3) = cos(tp(1))

  ! Check if the results are as expected
  if (all(abs(v - expected_v) < tolerance)) then
    print *, "Test Passed."
  else
    print *, "Test Failed."
  end if

contains

  subroutine sctovec(tp, v)
    implicit none
    real(8), intent(in) :: tp(2)
    real(8), intent(out) :: v(3)
    real(8) :: t1

    t1 = sin(tp(1))
    v(1) = t1 * cos(tp(2))
    v(2) = t1 * sin(tp(2))
    v(3) = cos(tp(1))
  end subroutine sctovec

end program test_sctovec