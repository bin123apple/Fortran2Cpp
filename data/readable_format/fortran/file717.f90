module udr7m1
    type dt
        real :: r
    end type dt
end module udr7m1

module udr7m2
    use udr7m1
    interface operator(+)
        module procedure addm2
    end interface
    interface operator(.myadd.)
        module procedure addm2
    end interface
contains
    type(dt) function addm2(x, y)
        type(dt), intent(in) :: x, y
        addm2%r = x%r + y%r
    end function addm2
end module udr7m2

module udr7m3
    use udr7m1
    interface operator(.myadd.)
        module procedure addm3
    end interface
    interface operator(+)
        module procedure addm3
    end interface
contains
    type(dt) function addm3(x, y)
        type(dt), intent(in) :: x, y
        addm3%r = x%r + y%r
    end function addm3
end module udr7m3

! Test procedures
subroutine TestUdr7m2
    use udr7m2
    type(dt) :: d1, d2, result

    d1 = dt(5.0)
    d2 = dt(10.0)

    result = d1 + d2
    if (result%r == 15.0) then
        print *, "Test udr7m2 (+) Passed"
    else
        print *, "Test udr7m2 (+) Failed"
    end if

    result = d1 .myadd. d2
    if (result%r == 15.0) then
        print *, "Test udr7m2 (.myadd.) Passed"
    else
        print *, "Test udr7m2 (.myadd.) Failed"
    end if
end subroutine TestUdr7m2

subroutine TestUdr7m3
    use udr7m3
    type(dt) :: d1, d2, result

    d1 = dt(5.0)
    d2 = dt(10.0)

    result = d1 + d2
    if (result%r == 15.0) then
        print *, "Test udr7m3 (+) Passed"
    else
        print *, "Test udr7m3 (+) Failed"
    end if

    result = d1 .myadd. d2
    if (result%r == 15.0) then
        print *, "Test udr7m3 (.myadd.) Passed"
    else
        print *, "Test udr7m3 (.myadd.) Failed"
    end if
end subroutine TestUdr7m3

program TestModules
    call TestUdr7m2
    call TestUdr7m3
end program TestModules