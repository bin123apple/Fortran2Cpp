program testDM3
    implicit none
    real :: result

    ! Test 1
    result = DM3(0.5)
    print *, "Test 1 (x=0.5): Expected: 0.5, Got:", result

    ! Test 2
    result = DM3(1.5)
    print *, "Test 2 (x=1.5): Expected: 0.0, Got:", result

    ! Test 3
    result = DM3(2.5)
    print *, "Test 3 (x=2.5): Expected: -0.5, Got:", result

contains

    real function DM3(x)
        implicit none
        real :: M2m, M2, x

        if ((x.ge.0.0).and.(x.le.2.0)) then
            M2m = 1.0 - abs(x - 1.0)
        else
            M2m = 0.0
        endif
        if ((x.ge.1.0).and.(x.le.3.0)) then
            M2 = 1.0 - abs(x - 2.0)
        else
            M2 = 0.0
        endif

        DM3 = M2m - M2
    end function DM3

end program testDM3