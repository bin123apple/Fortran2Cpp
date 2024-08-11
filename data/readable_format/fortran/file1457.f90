program testSizeCheck
  implicit none
  integer, parameter :: nsize = 5
  integer :: vector(5) = [1, 2, 3, 4, 5]
  character(len=*), parameter :: subname = 'TestProcedure'
  character(len=*), parameter :: vecname = 'TestVector'

  call checkVectorSize(vector, nsize, subname, vecname)
  print*, 'Test passed.'

contains

  subroutine checkVectorSize(vector, nsize, subname, vecname)
    integer, intent(in) :: vector(:), nsize
    character(len=*), intent(in) :: subname, vecname

    if (size(vector) /= nsize) then
      print*, 'FATAL ERROR: Size problem incompatibility!'
      print*, '  Inside Procedure: ', subname
      print*, '  Vector Name:      ', vecname
      print*, '  Expected size:    ', nsize
      print*, '  Actual size:      ', size(vector)
      stop
    end if
  end subroutine checkVectorSize

end program testSizeCheck