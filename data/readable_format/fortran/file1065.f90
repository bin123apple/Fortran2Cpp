module pfc1dfuns2
    implicit none
contains
    function F_hp_face(dxin, hin, zin, dxout, hout, zout, b)
        real :: dxin, dxout
        real :: hin, hout
        real :: zin, zout
        real :: b
        real :: F_hp_face
        real :: head_at_face, Zface
        head_at_face = ((hin + zin) * dxin + (hout + zout) * dxout) / (dxin + dxout)
        Zface = (zin * dxin + zout * dxout) / (dxin + dxout)
        F_hp_face = min(b, head_at_face - Zface)
    end function F_hp_face

    function F_hs_face(dxin, hin, zin, dxout, hout, zout, b)
        real :: dxin, dxout
        real :: hin, hout
        real :: zin, zout
        real :: b
        real :: F_hs_face
        real :: head_at_face, Zface
        head_at_face = ((hin + zin) * dxin + (hout + zout) * dxout) / (dxin + dxout)
        Zface = (zin * dxin + zout * dxout) / (dxin + dxout)
        F_hs_face = max(0.0, head_at_face - Zface - b)
    end function F_hs_face
end module pfc1dfuns2

program test_pfc1dfuns2
    use pfc1dfuns2
    implicit none

    real :: dxin = 2.0, dxout = 3.0, hin = 1.0, hout = 2.0
    real :: zin = 0.5, zout = 0.5, b = 1.5
    real :: result_hp, result_hs

    result_hp = F_hp_face(dxin, hin, zin, dxout, hout, zout, b)
    print *, "Test F_hp_face Result: ", result_hp

    result_hs = F_hs_face(dxin, hin, zin, dxout, hout, zout, b)
    print *, "Test F_hs_face Result: ", result_hs
end program test_pfc1dfuns2