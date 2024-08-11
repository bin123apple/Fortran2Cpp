! norm_test.f90
subroutine norm(vel, velnorm, nef)
    implicit none
    integer :: i, j, nef
    real(8) :: velnorm(0:4)
    real(8) :: vel(nef,0:7)

    ! Initialize velnorm with zeros
    velnorm = 0.0d0

    !$OMP PARALLEL DEFAULT(NONE) SHARED(velnorm,vel,nef) PRIVATE(i,j)
    !$OMP DO
    do i = 1, nef
        do j = 0, 4
            !$OMP ATOMIC
            velnorm(j) = velnorm(j) + vel(i,j)**2
        end do
    end do
    !$OMP END DO
    !$OMP END PARALLEL
end subroutine norm

program test_norm
    implicit none
    integer, parameter :: nef = 2
    real(8) :: velnorm(0:4)
    real(8) :: vel(nef,0:7)
    integer :: i, j

    ! Initialize vel with some test values
    do i = 1, nef
        do j = 0, 4
            vel(i,j) = i + j * 0.1
        end do
        do j = 5, 7
            vel(i,j) = 0.0
        end do
    end do

    ! Initialize velnorm with zeros
    velnorm = 0.0

    ! Call the norm subroutine
    call norm(vel, velnorm, nef)

    ! Output the results and manually check if they are as expected
    print *, "velnorm:"
    do i = 0, 4
        print *, "velnorm(", i, ") = ", velnorm(i)
    end do
end program test_norm