module charmmmod
    implicit none
    integer :: chmmntype, chmmbond, chmmang, chmmub, chmmdih, chmmimp, chmmcmap, &
               chmmnonb, chmmnbfix, chmmhbond, charmm_nmax  
    integer, allocatable :: charmm_btype(:,:), charmm_atype(:,:), charmm_ubtype(:,:), &
                           charmm_dtype(:,:), charmm_itype(:,:), charmm_icmap(:,:), &
                           charmm_icmap2(:,:)
    integer, allocatable :: charmm_lub(:), charmm_ndih(:,:), charmm_nprms(:), &
                           charmm_ncmap(:), charmm_typen(:,:)
    real, allocatable :: charmm_mass(:), charmm_bond(:,:), charmm_ang(:,:), &
                         charmm_ub(:,:), charmm_dih(:,:), charmm_imp(:,:), &
                         charmm_cmap(:), charmm_fcmap(:,:)
    real, allocatable :: charmm_nonbonded(:,:)
    character(len=7), allocatable :: charmm_label(:)
    logical :: Qchmmbond, Qchmmang, Qchmmub, Qchmmdih, Qchmmimp, Qchmmcmap, &
               Qchmmnbfix, Qchmmhbond

    integer, allocatable :: psf_atomtype(:), psf_atomtype2(:), psf_charge(:,:)
    real :: viscwat, scldiff

    logical :: DCDUnitCell
end module charmmmod

program test_charmmmod
    use charmmmod
    implicit none

    ! Example of how to use variables from the module
    ! (Actual test code or operations would go here)

    print *, "Module and program compiled successfully."
end program test_charmmmod