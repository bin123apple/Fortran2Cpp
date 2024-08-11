! EVTS_COWELL.f90
module KINDS
    implicit none
    integer, parameter :: ik = selected_int_kind(10)
    integer, parameter :: dk = selected_real_kind(15, 307)
    integer, parameter :: qk = selected_real_kind(15, 307)
end module KINDS

module CONSTANTS
    use KINDS
    implicit none
    real(qk), parameter :: DU = 1.0_qk, TU = 1.0_qk, wEarth = 1.0_qk, smaEarth = 1.0_qk
    real(dk), parameter :: secsPerDay = 86400.0_dk
    real(qk), parameter :: RSwitch = 1.0_qk
    real(dk), parameter :: JD_next = 2451545.0_dk, JD_stop = 2451546.0_dk
end module CONSTANTS

module AUXILIARIES
    use KINDS
    implicit none
    logical :: inSoI = .true.
end module AUXILIARIES

module EVTS_COWELL
    use KINDS
    use CONSTANTS
    use AUXILIARIES
    implicit none

contains

    subroutine QCOWELL_EVT(neq, t, y, ng, roots)
        integer(ik), intent(in) :: neq, ng
        real(qk), intent(in) :: t
        real(qk), intent(in) :: y(1:neq)
        real(qk), intent(out) :: roots(1:ng)
        real(qk) :: r_geo(1:3), r_Earth(1:3), lon_Earth, rMag

        if (inSoI) then
            r_geo = y(1:3)
        else
            lon_Earth = (wEarth / TU) * t
            r_Earth = (smaEarth / DU) * [cos(lon_Earth), sin(lon_Earth), 0._qk]
            r_geo = y(1:3) - r_Earth
        end if
        rMag = sqrt(sum(r_geo**2))

        roots(1) = rMag - RSwitch / DU
    end subroutine QCOWELL_EVT

    subroutine DCOWELL_EVT(neq, t, y, ng, roots)
        integer(ik), intent(in) :: neq, ng
        real(dk), intent(in) :: t
        real(dk), intent(in) :: y(1:neq)
        real(dk), intent(out) :: roots(1:ng)

        roots(1) = t - JD_next * secsPerDay / TU
        roots(2) = t - JD_stop * secsPerDay / TU
    end subroutine DCOWELL_EVT

end module EVTS_COWELL

program Test_EVTS_COWELL
    use EVTS_COWELL
    implicit none
    ! Variables
    integer(ik) :: neq, ng
    real(qk) :: t_qk
    real(dk) :: t_dk
    real(qk) :: y_qk(6) = [1.0_qk, 1.0_qk, 1.0_qk, 0.0_qk, 0.0_qk, 0.0_qk]
    real(dk) :: y_dk(6) = [1.0_dk, 1.0_dk, 1.0_dk, 0.0_dk, 0.0_dk, 0.0_dk]
    real(qk) :: roots_qk(1)
    real(dk) :: roots_dk(2)

    ! Test QCOWELL_EVT
    neq = 6
    ng = 1
    t_qk = 0.0_qk
    call QCOWELL_EVT(neq, t_qk, y_qk, ng, roots_qk)
    print *, 'Root (QCOWELL_EVT): ', roots_qk

    ! Test DCOWELL_EVT
    neq = 6
    ng = 2
    t_dk = 0.0_dk
    call DCOWELL_EVT(neq, t_dk, y_dk, ng, roots_dk)
    print *, 'Root 1 (DCOWELL_EVT): ', roots_dk(1)
    print *, 'Root 2 (DCOWELL_EVT): ', roots_dk(2)

end program Test_EVTS_COWELL