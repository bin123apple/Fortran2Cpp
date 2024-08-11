program test_insertsortd
    implicit none
    double precision :: dx(5) = [5.5d0, 2.2d0, 9.1d0, 3.3d0, 4.4d0]
    double precision :: dy(3) = [3.1d0, 1.2d0, 2.2d0]
    integer :: i

    call insertsortd(dx, 5)
    print *, 'Sorted dx:'
    do i=1,5
        print *, dx(i)
    end do

    call insertsortd(dy, 3)
    print *, 'Sorted dy:'
    do i=1,3
        print *, dy(i)
    end do
end program test_insertsortd

subroutine insertsortd(dx,n)
    implicit none
    integer n
    double precision dx(*)
    integer i,j
    double precision xtmp
    do i=2,n
        xtmp=dx(i)
        do j=i-1,1,-1
            if(xtmp.lt.dx(j)) then
                dx(j+1)=dx(j)
            else
                exit
            endif
        enddo
        dx(j+1)=xtmp
    enddo
    return
end