program test_write_tsde
  implicit none

  ! Variables
  character(len=20) :: fname = 'fortran_test.bin'
  integer, parameter :: no_u = 2, nspin = 2, nnz = 6
  integer, dimension(3) :: nsc = (/10, 10, 10/)
  integer, dimension(no_u) :: ncol = (/3, 3/)
  integer, dimension(nnz) :: list_col = (/1, 2, 3, 4, 5, 6/)
  real(kind=8), dimension(nnz, nspin) :: DM
  real(kind=8), dimension(nnz, nspin) :: EDM
  real(kind=8) :: Ef = 5.5
  integer :: i, j

  ! Initialize DM and EDM arrays
  do j = 1, nspin
    do i = 1, nnz
      DM(i, j) = 0.1 * i
      EDM(i, j) = 0.2 * i
    end do
  end do

  ! Call the subroutine
  call write_tsde_dm_edm(fname, nspin, no_u, nsc, nnz, ncol, list_col, DM, EDM, Ef)

  print *, "Test completed. Check 'fortran_test.bin' for output."
  
end program test_write_tsde

! Dummy subroutine to avoid compilation errors. Replace with your actual subroutine.
subroutine write_tsde_dm_edm(fname, nspin, no_u, nsc, nnz, ncol, list_col, DM, EDM, Ef)
  implicit none
  character(len=*), intent(in) :: fname
  integer, intent(in) :: no_u, nspin, nsc(3), nnz
  integer, intent(in) :: ncol(no_u), list_col(nnz)
  real(kind=8), intent(in) :: DM(nnz,nspin), EDM(nnz,nspin)
  real(kind=8), intent(in) :: Ef
  ! Implementation of the subroutine
end subroutine write_tsde_dm_edm