module foo
    implicit none
contains
    function n1(a) result(res)
        integer, intent(in) :: a
        integer :: res, c
        save c
        c = a
        res = c**3
    end function n1

    function n2(b) result(res)
        integer, intent(in) :: b
        integer :: res, c
        save c
        res = c * b
        res = res**2
    end function n2

    function z1(u) result(res)
        complex, intent(in) :: u
        complex :: res
        res = (1.0, 2.0) * u
    end function z1

    function z2(v) result(res)
        complex, intent(in) :: v
        complex :: res
        res = (3.0, 4.0) * v
    end function z2

    function n3(d) result(res)
        integer, intent(in) :: d
        integer :: res
        res = n2(d) * n1(d)
    end function n3

    function c1(a) result(res)
        character(len=*), intent(in) :: a
        character(len=4) :: res
        res = a
        if (a == "abcd") res = "ABCD"
    end function c1

    function c2(b) result(res)
        character(len=*), intent(in) :: b
        character(len=4) :: res
        res = b
        if (b == "wxyz") res = "WXYZ"
    end function c2

end module foo

program test_foo
    use foo
    implicit none
    complex :: zResult

    if (n1(9) /= 729) print *, "Test failed: n1(9) /= 729"
    if (n2(2) /= 324) print *, "Test failed: n2(2) /= 324"
    if (n3(19) /= 200564019) print *, "Test failed: n3(19) /= 200564019"
    
    if (c1("lmno") /= "lmno") print *, "Test failed: c1('lmno') /= 'lmno'"
    if (c1("abcd") /= "ABCD") print *, "Test failed: c1('abcd') /= 'ABCD'"
    if (c2("lmno") /= "lmno") print *, "Test failed: c2('lmno') /= 'lmno'"
    if (c2("wxyz") /= "WXYZ") print *, "Test failed: c2('wxyz') /= 'WXYZ'"
    
    zResult = z1((3.0, 4.0))
    if (zResult /= cmplx(-5.0, 10.0)) print *, "Test failed: z1((3,4)) /= (-5, 10)"
    
    zResult = z2((5.0, 6.0))
    if (zResult /= cmplx(-9.0, 38.0)) print *, "Test failed: z2((5,6)) /= (-9, 38)"
    
end program test_foo