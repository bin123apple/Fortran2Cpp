module m_dom_debug
  logical, save, public :: dom_debug = .false.
end module m_dom_debug

program test_dom_debug
  use m_dom_debug
  implicit none

  ! Test 1: Check initial value
  if (.not. dom_debug) then
    print *, "Test 1 Passed: dom_debug is initially .false."
  else
    print *, "Test 1 Failed: dom_debug is not .false."
  end if

  ! Change the value
  dom_debug = .true.

  ! Test 2: Check modified value
  if (dom_debug) then
    print *, "Test 2 Passed: dom_debug can be set to .true."
  else
    print *, "Test 2 Failed: dom_debug could not be set to .true."
  end if
end program test_dom_debug