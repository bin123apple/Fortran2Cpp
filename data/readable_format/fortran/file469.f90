program test_PBME_allocation
  implicit none
  
  ! Declare global variables here instead of using a module
  integer :: Lsite
  double precision :: t0
  
  ! Declare matrices and vectors here for direct access
  double precision, allocatable :: Hmat_kin(:,:), Hmat_coup(:,:), Hmat_tot(:,:)
  double precision, allocatable :: X_HO(:), V_HO(:), F_HO(:), X_HO_ini(:), V_HO_ini(:)
  double precision, allocatable :: x_m(:), p_m(:), zweight_m(:,:)
  
  ! Initialize global variables for the test
  Lsite = 5
  t0 = 1.0d0
  
  ! Allocation and initialization subroutine
  call PBME_allocation
  
  ! Now perform some checks
  if (all(Hmat_kin /= 0d0)) then
    print *, "Hmat_kin allocation and initialization test passed."
  else
    print *, "Hmat_kin allocation and initialization test failed."
  endif
  
contains

  subroutine PBME_allocation
    implicit none
    integer :: i, j
  
    ! Allocate matrices and vectors
    allocate(Hmat_kin(Lsite,Lsite), Hmat_coup(Lsite,Lsite), Hmat_tot(Lsite,Lsite))
    allocate(X_HO(Lsite), V_HO(Lsite), F_HO(Lsite), X_HO_ini(Lsite), V_HO_ini(Lsite))
    allocate(x_m(Lsite), p_m(Lsite), zweight_m(Lsite,Lsite))
  
    Hmat_kin = 0d0
    do i = 1, Lsite
      j = i + 1
      if (j > Lsite) j = j - Lsite
      Hmat_kin(i, j) = -t0
      j = i - 1
      if (j < 1) j = j + Lsite
      Hmat_kin(i, j) = -t0
    end do
  end subroutine PBME_allocation

end program test_PBME_allocation