program testFun
    implicit none
    double precision :: a, b, expected, result

    interface
        double precision function fun(a, b)
            double precision, intent(in) :: a, b
        end function fun
    end interface

    ! Test 1
    a = 1.0d-46
    b = 1.0d0
    expected = 1.0d-46
    result = fun(a, b)
    if (result == expected) then
        print *, 'Test 1 passed.'
    else
        print *, 'Test 1 failed.'
    end if

    ! Test 2
    a = 2.0d0
    b = 3.0d0
    expected = 6.0d0
    result = fun(a, b)
    if (result == expected) then
        print *, 'Test 2 passed.'
    else
        print *, 'Test 2 failed.'
    end if
end program testFun

! Original fun function
double precision function fun(a, b)
    double precision, intent(in) :: a, b
    print *, 'in sub: a,b=', a, b
    fun = a * b
    print *, 'in sub: fun=', fun
end function fun