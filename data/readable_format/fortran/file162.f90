module volmod
  implicit none
  integer, volatile :: a
  logical, volatile :: b
  logical :: c
contains
  subroutine sample
    a = 33
    if (a /= 432) then
      print *, 'aPresent'
    endif

    b = .false.
    if (b) then
      print *, 'bPresent'
    endif

    c = .false.
    if (c) then
      print *, 'cPresent'
    endif
  end subroutine sample
end module volmod

program main
  use volmod
  implicit none

  ! Test setup
  a = 432
  b = .false.
  c = .false.

  ! Initial state checks
  if (a == 432) then
    print *, 'Test 1a: a should initially be 432 - PASSED'
  else
    print *, 'Test 1a: a should initially be 432 - FAILED'
  endif

  if (.not. b) then
    print *, 'Test 1b: b should initially be .false. - PASSED'
  else
    print *, 'Test 1b: b should initially be .false. - FAILED'
  endif

  if (.not. c) then
    print *, 'Test 1c: c should initially be .false. - PASSED'
  else
    print *, 'Test 1c: c should initially be .false. - FAILED'
  endif

  ! Call the subroutine and check effects
  call sample

  if (a == 33) then
    print *, 'Test 2a: a should be 33 after sample - PASSED'
  else
    print *, 'Test 2a: a should be 33 after sample - FAILED'
  endif

  if (.not. b) then
    print *, 'Test 2b: b should remain .false. after sample - PASSED'
  else
    print *, 'Test 2b: b should remain .false. after sample - FAILED'
  endif

  if (.not. c) then
    print *, 'Test 2c: c should remain .false. after sample - PASSED'
  else
    print *, 'Test 2c: c should remain .false. after sample - FAILED'
  endif
end program main