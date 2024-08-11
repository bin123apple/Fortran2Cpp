module matsize_checks
  implicit none
contains
  subroutine check_matsize_n(nsize1, nsize2, matrix, matname, subname)
    integer, intent(in) :: nsize1, nsize2
    integer, intent(in) :: matrix(:,:)
    character(len=*), intent(in) :: matname, subname
    if (size(matrix, 1) /= nsize1 .or. size(matrix, 2) /= nsize2) then
      print *, "Error in ", trim(subname), ": Matrix ", trim(matname), " has incorrect size."
    else
      print *, "Matrix ", trim(matname), " checked successfully in ", trim(subname), "."
    end if
  end subroutine check_matsize_n

  subroutine check_matsize_r(nsize1, nsize2, matrix, matname, subname)
    integer, intent(in) :: nsize1, nsize2
    real, intent(in) :: matrix(:,:)
    character(len=*), intent(in) :: matname, subname
    if (size(matrix, 1) /= nsize1 .or. size(matrix, 2) /= nsize2) then
      print *, "Error in ", trim(subname), ": Matrix ", trim(matname), " has incorrect size."
    else
      print *, "Matrix ", trim(matname), " checked successfully in ", trim(subname), "."
    end if
  end subroutine check_matsize_r
end module matsize_checks

program test_check_matsize
  use matsize_checks
  implicit none
  integer :: i, j
  integer, allocatable :: intMatrix(:,:)
  real, allocatable :: realMatrix(:,:)

  ! Define a small integer matrix for testing
  allocate(intMatrix(2,2))
  intMatrix = reshape([1, 2, 3, 4], shape(intMatrix))

  ! Define a small real matrix for testing
  allocate(realMatrix(2,2))
  realMatrix = reshape([1.0, 2.0, 3.0, 4.0], shape(realMatrix))

  ! Test integer matrix of correct size
  call check_matsize_n(2, 2, intMatrix, 'intMatrix', 'test_check_matsize')

  ! Test real matrix of correct size
  call check_matsize_r(2, 2, realMatrix, 'realMatrix', 'test_check_matsize')

  ! Add more tests as necessary

end program test_check_matsize