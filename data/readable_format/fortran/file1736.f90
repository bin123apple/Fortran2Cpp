program test_putevalfv
    implicit none
    ! Assuming vkl, nstfv, nspnfv and other necessary definitions were part of modmain
    integer, parameter :: nstfv = 2, nspnfv = 2
    real(8) :: vkl(3, 1) ! Example definition, adjust as needed
    real(8), allocatable :: evalfv(:,:)
    integer :: ik
    character(len=10) :: fext = '.test'
    integer :: i, j

    ! Initialize vkl
    vkl(:, 1) = (/1.0d0, 2.0d0, 3.0d0/)

    ! Initialize evalfv
    allocate(evalfv(nstfv, nspnfv))
    do i = 1, nstfv
       do j = 1, nspnfv
          evalfv(i, j) = i + j * 0.1d0
       end do
    end do

    ik = 1

    ! Call the subroutine
    call putevalfv(fext, ik, evalfv)

    ! Clean up
    deallocate(evalfv)

    print *, "Test executed, check the EVALFV"//trim(fext)//" file for output."

contains

    subroutine putevalfv(fext, ik, evalfv)
    implicit none
    character(len=*), intent(in) :: fext
    integer, intent(in) :: ik
    real(8), intent(in) :: evalfv(nstfv,nspnfv)
    integer :: recl
    ! Here you would replace modmain usage with direct code or adapted code
    ! As an example, we directly use variables declared in the main program

    inquire(iolength=recl) vkl(:,ik), nstfv, nspnfv, evalfv
    !$OMP CRITICAL(u120)
    open(120, file='EVALFV'//trim(fext), form='UNFORMATTED', access='DIRECT', recl=recl)
    write(120, rec=ik) vkl(:,ik), nstfv, nspnfv, evalfv
    close(120)
    !$OMP END CRITICAL(u120)
    end subroutine putevalfv

end program test_putevalfv