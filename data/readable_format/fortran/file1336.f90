program test_f1
  implicit none

  call f1

  print *, "Fortran subroutine f1 executed successfully."
end program test_f1

subroutine f1
  implicit none

  !$acc kernels default(none)
  !$acc end kernels
  !$acc parallel default(none)
  !$acc end parallel

  !$acc kernels default(present)
  !$acc end kernels
  !$acc parallel default(present)
  !$acc end parallel
end subroutine f1