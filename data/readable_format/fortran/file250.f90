module neutrinoInfoStorage
    implicit none
    private

    type tneutrinoInfoStorage
        logical :: flagOK = .False.
        real    :: value = 0.
        real    :: value_rec = 0.
        real    :: value_rec_2 = 0.
    end type tneutrinoInfoStorage

    type(tneutrinoInfoStorage), save, dimension(:), allocatable :: EXP_nuInfo

    public :: neutrinoInfoStorage_Init, neutrinoInfoStorage_Clear, isAllocated

contains

    subroutine neutrinoInfoStorage_Init(NumInitialEvents)
        integer, intent(in) :: NumInitialEvents

        if (allocated(EXP_nuInfo)) then
            deallocate(EXP_nuInfo)
        endif
        allocate(EXP_nuInfo(1:NumInitialEvents))
        EXP_nuInfo%flagOK = .false.
        EXP_nuInfo%value = 0.
        EXP_nuInfo%value_rec = 0.
        EXP_nuInfo%value_rec_2 = 0.
    end subroutine neutrinoInfoStorage_Init

    subroutine neutrinoInfoStorage_Clear()
        if (allocated(EXP_nuInfo)) then
            deallocate(EXP_nuInfo)
        endif
    end subroutine neutrinoInfoStorage_Clear

    function isAllocated() result(allocStatus)
        logical :: allocStatus
        allocStatus = allocated(EXP_nuInfo)
    end function isAllocated

end module neutrinoInfoStorage

program testNeutrinoInfoStorage
    use neutrinoInfoStorage
    implicit none

    call neutrinoInfoStorage_Init(5)
    print *, 'NeutrinoInfoStorage initialized with 5 events.'

    if (isAllocated()) then
        print *, 'Test PASS: EXP_nuInfo is allocated.'
    else
        print *, 'Test FAIL: EXP_nuInfo is not allocated.'
    endif

    call neutrinoInfoStorage_Clear()
    print *, 'NeutrinoInfoStorage cleared.'

    if (.not. isAllocated()) then
        print *, 'Test PASS: EXP_nuInfo is not allocated after clear.'
    else
        print *, 'Test FAIL: EXP_nuInfo is still allocated after clear.'
    endif

end program testNeutrinoInfoStorage