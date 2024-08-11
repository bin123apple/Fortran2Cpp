module prepare_timerun_init_wavefield__genmod
  implicit none
contains
  subroutine prepare_timerun_init_wavefield(result)
    integer, intent(out) :: result
    result = 42
  end subroutine prepare_timerun_init_wavefield
end module prepare_timerun_init_wavefield__genmod

program test_prepare_timerun_init_wavefield
  use prepare_timerun_init_wavefield__genmod
  implicit none
  integer :: result

  call prepare_timerun_init_wavefield(result)
  
  if (result == 42) then
    print *, "Test passed. Result is: ", result
  else
    print *, "Test failed."
  end if
end program test_prepare_timerun_init_wavefield