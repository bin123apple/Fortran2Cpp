module darfgr_mod
contains
    subroutine DARFGR(JOB, Q1, Q2, INFO)
        implicit none
        character(len=1), intent(in) :: JOB
        double precision, intent(inout) :: Q1(2), Q2(2)
        integer, intent(out) :: INFO
        double precision :: nrm

        INFO = 0
        if (JOB == 'R') then
            nrm = Q1(1)*Q2(1) - Q1(2)*Q2(2)
            Q1(2) = Q1(2)*Q2(1) + Q1(1)*Q2(2)
            Q1(1) = nrm
        else if (JOB == 'L') then
            nrm = Q1(1)*Q2(1) - Q1(2)*Q2(2)
            Q2(2) = Q1(2)*Q2(1) + Q1(1)*Q2(2)
            Q2(1) = nrm
        else
            INFO = -1
        end if
    end subroutine DARFGR
end module darfgr_mod

program test
    use darfgr_mod
    implicit none
    double precision :: Q1(2), Q2(2)
    integer :: INFO
    character(len=1) :: JOB

    ! Test case setup
    JOB = 'R'
    INFO = 0
    Q1 = [1.0d0, 2.0d0]
    Q2 = [3.0d0, 4.0d0]

    call DARFGR(JOB, Q1, Q2, INFO)

    print *, "INFO:", INFO
    print *, "Q1 after DARFGR:", Q1
    print *, "Q2 after DARFGR:", Q2
end program test