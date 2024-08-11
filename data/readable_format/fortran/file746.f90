program test_bad1
    double precision :: d
    call bad1(d)
    print *, "Value of d: ", d
end program test_bad1

subroutine bad1(d)
    double precision :: d
    d = 5.0
end subroutine bad1