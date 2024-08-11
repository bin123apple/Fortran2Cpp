program testC
    implicit none
    integer(4) :: X
    X = 1 ! Example value
    call C(X)
    print *, "After C, X =", X
    ! Expected output: X shifted left by 8, so if X was 1, it should now be 256
end program testC

subroutine C(X)
    implicit none
    integer(4), intent(inout) :: X
    integer(4) :: RES
    RES = ishft(X, 8)
    X = RES
end subroutine C