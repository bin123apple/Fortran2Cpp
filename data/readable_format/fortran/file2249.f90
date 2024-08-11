program test_linvec10
    implicit none
    integer :: konl(4)
    real(8) :: vec(3, 4)
    real(8) :: vecl(3)
    real(8) :: shp(4, 10)

    ! Initialize test data
    konl = (/1, 2, 3, 4/)
    vec = reshape([1.0d0, 2.0d0, 3.0d0, 4.0d0, &
                    5.0d0, 6.0d0, 7.0d0, 8.0d0, &
                    9.0d0, 10.0d0, 11.0d0, 12.0d0], shape(vec), order=[2,1])
    shp = reshape([0.1d0, 0.2d0, 0.3d0, 0.4d0, 0.5d0, 0.6d0, 0.7d0, 0.8d0, 0.9d0, 1.0d0, &
                    0.1d0, 0.2d0, 0.3d0, 0.4d0, 0.5d0, 0.6d0, 0.7d0, 0.8d0, 0.9d0, 1.0d0, &
                    0.1d0, 0.2d0, 0.3d0, 0.4d0, 0.5d0, 0.6d0, 0.7d0, 0.8d0, 0.9d0, 1.0d0, &
                    0.1d0, 0.2d0, 0.3d0, 0.4d0, 0.5d0, 0.6d0, 0.7d0, 0.8d0, 0.9d0, 1.0d0], shape(shp), order=[2,1])

    ! Call the subroutine
    call linvec10(vec, konl, vecl, shp)

    ! Print the result
    print *, 'vecl = ', vecl
end program test_linvec10

subroutine linvec10(vec, konl, vecl, shp)
    implicit none
    integer :: konl(4)
    real(8) :: vec(3, 4)
    real(8) :: vecl(3)
    real(8) :: shp(4, 10)
    integer :: j

    do j = 1, 3
        vecl(j) = (shp(4, 1) + (shp(4, 5) + shp(4, 7) + shp(4, 8)) / 2.d0) * vec(j, konl(1)) + &
                  (shp(4, 2) + (shp(4, 5) + shp(4, 6) + shp(4, 9)) / 2.d0) * vec(j, konl(2)) + &
                  (shp(4, 3) + (shp(4, 6) + shp(4, 7) + shp(4, 10)) / 2.d0) * vec(j, konl(3)) + &
                  (shp(4, 4) + (shp(4, 8) + shp(4, 9) + shp(4, 10)) / 2.d0) * vec(j, konl(4))
    end do
end subroutine linvec10