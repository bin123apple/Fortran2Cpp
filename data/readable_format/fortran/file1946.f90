module mandelbrot_module
  implicit none
  integer, parameter :: dp = selected_real_kind(15, 307) ! Double precision kind
contains
  function calculateMandelbrotArea(npoints, maxiter) result(area)
    implicit none
    integer, intent(in) :: npoints, maxiter
    real(kind=dp) :: area
    integer :: i, j, iter, numoutside
    complex(kind=dp) :: c, z
    
    numoutside = 0

    do i = 0, npoints-1
       do j= 0, npoints-1
          c = cmplx(-2.0_dp + (2.5_dp * i) / npoints, (1.125_dp * j) / npoints, kind=dp)
          z = c
          iter = 0
          do while (iter < maxiter)
             z = z*z + c
             iter = iter + 1
             if (real(z)*real(z) + aimag(z)*aimag(z) > 4.0_dp) then
                numoutside = numoutside + 1
                exit
             end if
          end do
       end do
    end do
    
    area = 2.0_dp * 2.5_dp * 1.125_dp * real(npoints * npoints - numoutside, kind=dp) / real(npoints * npoints, kind=dp)
  end function calculateMandelbrotArea
end module mandelbrot_module

program test_mandelbrot
  use mandelbrot_module
  implicit none

  real(kind=dp) :: computed_area

  computed_area = calculateMandelbrotArea(200, 200) ! Using smaller values for a quick test
  print *, "Computed Area: ", computed_area
end program test_mandelbrot