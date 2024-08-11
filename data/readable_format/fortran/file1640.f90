program test_reorderrhs
    implicit none
    integer, parameter :: n = 5, m = 3
    real*8 :: a(n), b(n), vold(n)
    integer :: neighblock(3,m)
    integer :: nneighblock
    integer :: i

    ! Initialize arrays
    a = (/1.0d0, 2.0d0, 3.0d0, 4.0d0, 5.0d0/)
    b = (/5.0d0, 4.0d0, 3.0d0, 2.0d0, 1.0d0/)
    vold = (/1.0d0, 2.0d0, 3.0d0, 4.0d0, 5.0d0/)
    neighblock = reshape((/1, 2, 3, 2, 3, 4, 3, 4, 5/), shape(neighblock))
    nneighblock = 3

    ! Call the subroutine
    call reorderrhs(a, b, vold, neighblock, nneighblock)

    ! Output the result for verification
    print *, 'Modified b:'
    do i = 1, n
        print *, b(i)
    end do

contains

    subroutine reorderrhs(a, b, vold, neighblock, nneighblock)
        implicit none
        integer neighblock(3,*),nneighblock,i,j,indexf,iel
        real*8 a(*),b(*),vold(*)

        do j=1,nneighblock
            indexf=neighblock(1,j)
            iel=neighblock(2,j)
            i=neighblock(3,j)
            b(i)=b(i)-a(indexf)*vold(iel)
        enddo

    end subroutine reorderrhs

end program test_reorderrhs