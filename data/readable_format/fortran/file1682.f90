! cb_module.f90
module cb
  implicit none
  real, dimension(10,10) :: b
end module cb

! test_cb.f90
program test_cb
  use cb
  implicit none

  ! Set a value
  b(6, 6) = 3.14

  ! Test
  if (b(6, 6) == 3.14) then
    print *, "Test passed: b(6, 6) is 3.14"
  else
    print *, "Test failed: b(6, 6) is not 3.14"
  end if

end program test_cb