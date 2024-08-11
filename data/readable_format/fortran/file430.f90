module bmod
    implicit none
    integer :: a, b, c, d, e, f, g, h, i
    common /data1/ a, b, c
    common /data2/ d, e, f
    common /data3/ g, h, i
end module

module amod
contains
    subroutine asubr(b)
        implicit none
        integer :: b(8)
        b = 2*b ! Example operation for testing
    end subroutine asubr
end module

program test
    use amod
    use bmod
    implicit none
    integer :: array(8) = (/1, 2, 3, 4, 5, 6, 7, 8/)
    integer :: j

    ! Test subroutine in amod
    call asubr(array)
    print *, "After asubr call: ", array

    ! Initialize common blocks
    a = 1; b = 2; c = 3
    d = 4; e = 5; f = 6
    g = 7; h = 8; i = 9

    ! Test common blocks
    print *, "Common block data1: ", a, b, c
    print *, "Common block data2: ", d, e, f
    print *, "Common block data3: ", g, h, i
end program test