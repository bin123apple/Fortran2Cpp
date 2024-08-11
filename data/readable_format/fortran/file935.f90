program test_mysub
    implicit none
    real(kind=8) :: a, b, c, d

    ! Test case 1
    a = 5.0
    b = 3.0
    call mysub(a, b, c, d)
    if (c == 8.0 .and. d == 2.0) then
        print *, 'Test 1 passed.'
    else
        print *, 'Test 1 failed.'
    end if

    ! Add more test cases as needed
    ! Test case 2
    a = -1.0
    b = -2.0
    call mysub(a, b, c, d)
    if (c == -3.0 .and. d == 1.0) then
        print *, 'Test 2 passed.'
    else
        print *, 'Test 2 failed.'
    end if

end program test_mysub

subroutine mysub(a,b,c,d)
    real (kind=8), intent(in) :: a,b
    real (kind=8), intent(out) :: c,d
    c = a + b
    d = a - b
end subroutine mysub