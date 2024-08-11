subroutine unpackpfx(ng, call1)
    implicit none
    integer, intent(in) :: ng
    character(len=20), intent(inout) :: call1
    character(len=3) :: pfx
    integer :: n, i, nc, nc1, nc2, i1

    if (ng < 60000) then
        n = ng
        do i = 3, 1, -1
            nc = mod(n, 37)
            if (nc >= 0 .and. nc <= 9) then
                pfx(i:i) = char(nc + 48)
            else if (nc >= 10 .and. nc <= 35) then
                pfx(i:i) = char(nc + 55)
            else
                pfx(i:i) = ' '
            end if
            n = n / 37
        end do
        call1 = trim(adjustl(pfx)) // '/' // call1
    else
        i1 = index(trim(call1), ' ')
        if (i1 == 0) then
            i1 = len(trim(call1)) + 1
        end if
        nc = ng - 60000
        if (nc >= 0 .and. nc <= 9) then
            call1 = call1(1:i1-1) // '/' // char(nc + 48)
        else if (nc >= 10 .and. nc <= 35) then
            call1 = call1(1:i1-1) // '/' // char(nc + 55)
        else if (nc >= 36 .and. nc <= 125) then
            nc1 = (nc - 26) / 10
            nc2 = mod(nc - 26, 10)
            call1 = call1(1:i1-1) // '/' // char(nc1 + 48) // char(nc2 + 48)
        end if
    end if
end subroutine unpackpfx

program test
    implicit none
    character(len=20) :: call1
    integer :: ng

    ! Test Case 1
    call1 = "examplecall"
    ng = 12345
    call unpackpfx(ng, call1)
    print *, "Fortran Test Result 1: ", call1

    ! Test Case 2
    call1 = "examplecall"
    ng = 60005
    call unpackpfx(ng, call1)
    print *, "Fortran Test Result 2: ", call1
end program test