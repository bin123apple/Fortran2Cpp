! ufaceload.f90
subroutine ufaceload(co, ipkon, kon, lakon, nboun, nodeboun, nelemload, sideload, nload, ne, nk, nload_dim2)
    implicit none
    integer, intent(in) :: ipkon(*), kon(*), nk, ne, nboun, nodeboun(*), nload, nload_dim2
    integer, intent(inout) :: nelemload(2, nload_dim2)
    real(8), intent(in) :: co(3,*)
    character(len=8), intent(in) :: lakon(*)
    character(len=20), intent(in) :: sideload(*)
    integer :: i, j
    
    ! Increment each element in nelemload by 1
    do j = 1, nload_dim2
        do i = 1, 2
            nelemload(i, j) = nelemload(i, j) + 1
        end do
    end do
end subroutine ufaceload

program test
    implicit none
    integer, parameter :: nload_dim2 = 5
    integer :: nelemload(2,nload_dim2) = reshape([1, 2, 3, 4, 5, 6, 7, 8, 9, 10], [2, nload_dim2])
    integer :: ipkon(1), kon(1), nboun, nodeboun(1), nload, ne, nk
    real(8) :: co(3,1)
    character(len=8) :: lakon(1)
    character(len=20) :: sideload(1)
    
    nboun = 1
    nload = 1
    ne = 1
    nk = 1
    nload = nload_dim2
    
    call ufaceload(co, ipkon, kon, lakon, nboun, nodeboun, nelemload, sideload, nload, ne, nk, nload_dim2)
    
    print *, "Modified nelemload:"
    print *, nelemload
end program test