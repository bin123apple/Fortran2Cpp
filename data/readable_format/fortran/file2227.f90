program test_enq_v1_teldef
    implicit none

    integer :: nae_max, nsp_max, nba_max, nch_max
    integer :: s
    integer, parameter :: max_aes = 100  ! Assumed value, replace with the actual value
    integer, parameter :: max_spac = 50  ! Assumed value, replace with the actual value

    ! Example value for s
    s = 0

    ! Call the subroutine
    call enq_v1_teldef(nae_max, nsp_max, nba_max, nch_max, s)

    ! Print the results
    print *, 'nae_max: ', nae_max
    print *, 'nsp_max: ', nsp_max
    print *, 'nba_max: ', nba_max
    print *, 'nch_max: ', nch_max

    ! Check the results
    if (nae_max /= max_aes) then
        print *, 'Test failed: nae_max is incorrect'
    else if (nsp_max /= max_spac) then
        print *, 'Test failed: nsp_max is incorrect'
    else if (nba_max /= 1) then
        print *, 'Test failed: nba_max is incorrect'
    else if (nch_max /= 1) then
        print *, 'Test failed: nch_max is incorrect'
    else
        print *, 'All tests passed!'
    end if

contains

    subroutine enq_v1_teldef(nae_max, nsp_max, nba_max, nch_max, s)
        integer, intent(inout) :: nae_max, nsp_max, nba_max, nch_max
        integer, intent(in) :: s

        ! Assuming these constants are defined inside the subroutine for simplicity
        integer, parameter :: max_aes = 100  ! Assumed value
        integer, parameter :: max_spac = 50  ! Assumed value

        if ( s /= 0 ) return

        nae_max = max_aes
        nsp_max = max_spac
        nba_max = 1
        nch_max = 1

    end subroutine enq_v1_teldef

end program test_enq_v1_teldef