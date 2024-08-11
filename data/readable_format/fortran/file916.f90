program test_mvbits
    implicit none
    integer(kind=8) :: i8 = 0
    integer(kind=4) :: i4 = 0
    integer(kind=2) :: i2 = 0
    integer(kind=1) :: i1 = 0

    call mvbits(1_1, 0, 8, i1, 0)
    print *, 'Test for i1:', i1

    call mvbits(1_2, 0, 16, i2, 0)
    print *, 'Test for i2:', i2

    call mvbits(1_4, 0, 16, i4, 0)
    print *, 'Test for i4:', i4

    call mvbits(1_8, 0, 16, i8, 0)
    print *, 'Test for i8:', i8
end program test_mvbits