program main
    character (len=4) :: a, b
    character (len=3) :: c(2)
    equivalence (a, c(1)), (b, c(2))

    ! Test 1: Modify 'a' and check 'c(1)'
    a = 'abc'
    if (c(1) /= 'abc') error stop "Test 1 failed"

    ! Test 2: Modify 'c(2)' and check it reflects in 'b'
    c(2) = 'def'
    if (b(1:3) /= 'def') error stop "Test 2 failed"

    print *, "All tests passed."
end program main