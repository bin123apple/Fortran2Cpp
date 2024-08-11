program test_euler_151
    use, intrinsic :: iso_fortran_env, only: dp=>real64
    implicit none
    real(dp) :: result

    ! Test Case 1
    result = paper(1, 1, 1, 1)
    print '("Test Case 1: ", f0.6)', result

    ! More test cases can be added here...

contains

    recursive function paper(a2, a3, a4, a5) result(p)
        integer, intent(in) :: a2, a3, a4, a5
        real(dp) :: p
        real(dp) :: p2, p3, p4, p5
        
        p2 = 0.0_dp; p3 = 0.0_dp; p4 = 0.0_dp; p5 = 0.0_dp
        
        if (a5==1 .and. a2+a3+a4==0) then
            p = 0.0_dp
        else if (a4==1 .and. a2+a3+a5==0) then
            p = 1.0_dp
        else if (a3==1 .and. a2+a4+a5==0) then
            p = 1.0_dp
        else if (a2==1 .and. a3+a4+a5==0) then
            p = 1.0_dp
        else
            if (a2 > 0) p2 = a2*paper(a2-1, a3+1, a4+1, a5+1)
            if (a3 > 0) p3 = a3*paper(a2, a3-1, a4+1, a5+1)
            if (a4 > 0) p4 = a4*paper(a2, a3, a4-1, a5+1)
            if (a5 > 0) p5 = a5*paper(a2, a3, a4, a5-1)
            p = (p2 + p3 + p4 + p5) / (a2 + a3 + a4 + a5)
        end if
    end function paper

end program test_euler_151