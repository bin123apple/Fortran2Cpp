program ConfigureMdRetrievalTest
    implicit none

    ! Define structures (derived types in Fortran)
    type :: MethStruct
        character(len=100) :: tlag
        character(len=100) :: det
        character(len=100) :: rot
        character(len=100) :: qcflag
        character(len=100) :: foot
    end type MethStruct

    type :: RUsetupStruct
        character(len=100) :: meth
    end type RUsetupStruct

    type :: RPsetupStruct
        character(len=100) :: bu_corr
        character(len=100) :: calib_aoa
        logical :: bu_multi
        logical :: calib_cw
        logical :: filter_by_raw_flags
        real(8) :: offset(3)
        logical :: out_st
        logical :: filter_sr
        logical :: filter_al
        logical :: out_qc_details
        logical :: out_raw
        logical :: out_bin_sp
        logical :: out_bin_og
        logical :: out_full_sp
        logical :: out_full_cosp
    end type RPsetupStruct

    type :: EddyProProjStruct
        logical :: use_extmd_file
        character(len=100) :: biomet_data
        logical :: wpl
        character(len=100) :: hf_meth
        logical :: out_md
        logical :: out_fluxnet
        logical :: out_full
        logical :: out_avrg_cosp
        logical :: out_biomet
        logical :: fcc_follows
        logical :: make_dataset
    end type EddyProProjStruct

    type :: TestStruct
        logical :: sr
        logical :: ar
        logical :: do
        logical :: al
        logical :: sk
        logical :: ds
        logical :: tl
        logical :: aa
        logical :: ns
    end type TestStruct

    ! Declare variables of derived types
    type(MethStruct) :: Meth
    type(RUsetupStruct) :: RUsetup
    type(RPsetupStruct) :: RPsetup
    type(EddyProProjStruct) :: EddyProProj
    type(TestStruct) :: Test

    ! Call the subroutine
    call ConfigureForMdRetrieval()

    ! Optionally, print some variables to verify
    print *, 'Meth%tlag = ', Meth%tlag
    print *, 'EddyProProj%use_extmd_file = ', EddyProProj%use_extmd_file

contains

    subroutine ConfigureForMdRetrieval()
        ! Set the initial values for each variable
        Meth%tlag = 'none'
        Meth%det = 'ba'
        Meth%rot = 'none'
        Meth%qcflag = 'none'
        Meth%foot = 'none'
        RUsetup%meth = 'none'
        RPsetup%bu_corr = 'none'
        RPsetup%calib_aoa = 'none'
        RPsetup%bu_multi = .false.
        RPsetup%calib_cw = .false.
        RPsetup%filter_by_raw_flags = .false.
        EddyProProj%use_extmd_file = .false.
        EddyProProj%biomet_data = 'none'
        EddyProProj%wpl = .false.
        EddyProProj%hf_meth = 'none'

        Test%sr = .false.
        Test%ar = .false.
        Test%do = .false.
        Test%al = .false.
        Test%sk = .false.
        Test%ds = .false.
        Test%tl = .false.
        Test%aa = .false.
        Test%ns = .false.
        RPsetup%offset(1) = 0d0
        RPsetup%offset(2) = 0d0
        RPsetup%offset(3) = 0d0

        EddyProProj%out_md = .true.
        EddyProProj%out_fluxnet = .false.
        EddyProProj%out_full = .false.
        EddyProProj%out_avrg_cosp = .false.
        EddyProProj%out_biomet = .false.
        RPsetup%out_st = .false.
        RPsetup%filter_sr = .false.
        RPsetup%filter_al = .false.
        RPsetup%out_qc_details = .false.
        RPsetup%out_raw = .false.
        RPsetup%out_bin_sp = .false.
        RPsetup%out_bin_og = .false.
        RPsetup%out_full_sp = .false.
        RPsetup%out_full_cosp = .false.
        EddyProProj%fcc_follows = .false.
        EddyProProj%make_dataset = .true.
    end subroutine ConfigureForMdRetrieval

end program ConfigureMdRetrievalTest