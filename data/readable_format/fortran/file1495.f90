program testProg
    implicit none
    integer :: i
    integer, dimension(2) :: nums
    integer :: numx
    integer, dimension(4) :: numse

    common /scr/ nums, numx
    equivalence (nums, numse(1)), (numx, numse(3))

    ! Main logic
    do i = 1, 4
        numse(i) = 10 + i
    end do

    ! Testing
    call testNums()
    call testNumse()
    call testNumx()

    print *, 'Fortran tests passed.'
end program testProg

subroutine testNums()
    integer, dimension(2) :: nums
    integer :: numx
    common /scr/ nums, numx
    integer expected(2)
    data expected /11, 12/
    if (all(nums == expected)) then
        print *, 'Nums test passed.'
    else
        print *, 'Nums test failed.'
    end if
end subroutine testNums

subroutine testNumse()
    integer, dimension(2) :: nums
    integer :: numx
    integer, dimension(4) :: numse
    common /scr/ nums, numx
    equivalence (nums, numse(1)), (numx, numse(3))
    integer expected(4)
    data expected /11, 12, 13, 14/
    if (all(numse == expected)) then
        print *, 'Numse test passed.'
    else
        print *, 'Numse test failed.'
    end if
end subroutine testNumse

subroutine testNumx()
    integer, dimension(2) :: nums
    integer :: numx
    common /scr/ nums, numx
    integer expected
    expected = 13
    if (numx == expected) then
        print *, 'Numx test passed.'
    else
        print *, 'Numx test failed.'
    end if
end subroutine testNumx