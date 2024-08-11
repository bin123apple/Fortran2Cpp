program gfcbu84_main
  implicit none
  integer           :: jplev, k_lev, i
  real :: p(42)
  real, pointer :: q(:)
  logical :: test_passed

  ! Initialize test data
  jplev = 42
  k_lev = 1
  allocate (q(jplev))
  p = [(i*1.0, i = 1, jplev)]  ! Initialize p with 1.0, 2.0, ..., 42.0

  ! Call the subroutine
  call tq_tvgh (q(k_lev:), p(k_lev:))

  ! Test the result
  test_passed = .true.
  do i = k_lev, jplev
    if (q(i) /= p(i)) then
      test_passed = .false.
      exit
    end if
  end do

  ! Print test result
  if (test_passed) then
    print *, "Test Passed"
  else
    print *, "Test Failed"
  end if

  deallocate (q)

contains
  elemental subroutine tq_tvgh (t, p)
    real ,intent (out)            :: t
    real ,intent (in)             :: p
    t=p
  end subroutine tq_tvgh
end program gfcbu84_main