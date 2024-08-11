program test
    implicit none
    integer,dimension(10)::n1
    integer::n2(10)
    integer,dimension(5,15,20)::n3
    integer::n4(5,15,20)
    integer,dimension(-5:5,-15:15,-20:20)::n5
    integer::n6(-5:5,-15:15,-20:20)
    integer::i, j, k

    ! Assign values
    n1(1) = 1
    n2(10) = 10
    n3(1,1,1) = 111
    n4(5,15,20) = 5120
    n5(-5,-15,-20) = -551520
    n6(5,15,20) = 551520

    ! Check values
    if (n1(1) /= 1) stop 'Test failed for n1.'
    if (n2(10) /= 10) stop 'Test failed for n2.'
    if (n3(1,1,1) /= 111) stop 'Test failed for n3.'
    if (n4(5,15,20) /= 5120) stop 'Test failed for n4.'
    if (n5(-5,-15,-20) /= -551520) stop 'Test failed for n5.'
    if (n6(5,15,20) /= 551520) stop 'Test failed for n6.'

    print *, 'All Fortran tests passed.'
end program test