program vla_test
  implicit none
  real, target, allocatable :: vla1 (:, :, :)
  real, target, allocatable :: vla2 (:, :, :)
  real, target, allocatable :: vla3 (:, :)
  real, pointer :: pvla (:, :, :)
  logical :: l

  ! Allocate and initialize arrays
  allocate (vla1 (10,10,10))
  allocate (vla2 (1:7,42:50,13:35))
  vla1 = 1311
  vla1(3, 6, 9) = 42
  vla1(1, 3, 8) = 1001
  vla1(6, 2, 7) = 13

  vla2 = 1311
  vla2(5, 45, 20) = 42

  ! Test assignments
  if (vla1(3, 6, 9) == 42) then
    print *, "Test 1 passed."
  else
    print *, "Test 1 failed."
  endif

  if (vla2(5, 45, 20) == 42) then
    print *, "Test 2 passed."
  else
    print *, "Test 2 failed."
  endif

  ! Test pointer reassignment and access
  pvla => vla1
  if (associated(pvla, vla1)) then
    print *, "Pointer test 1 passed."
  else
    print *, "Pointer test 1 failed."
  endif

  pvla => vla2
  pvla(5, 45, 20) = 1
  if (vla2(5, 45, 20) == 1) then
    print *, "Pointer test 2 passed."
  else
    print *, "Pointer test 2 failed."
  endif

  ! Clean up
  deallocate(vla1, vla2, vla3)
end program vla_test