module h5global
  implicit none
  integer :: h5p_default_f, h5p_flags
  equivalence(h5p_flags, h5p_default_f)
end module h5global

program test_h5global
  use h5global
  implicit none

  ! Set the value of h5p_default_f
  h5p_default_f = 42

  ! Check if h5p_flags has the same value as h5p_default_f
  if (h5p_flags /= 42) then
    print *, "Test failed: h5p_flags does not match h5p_default_f"
    stop 1
  else
    print *, "Test passed: h5p_flags matches h5p_default_f"
  end if

end program test_h5global