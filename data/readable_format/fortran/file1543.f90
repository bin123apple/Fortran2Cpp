program test_caxpy
  implicit none
  complex :: ca
  integer :: n, incx, incy

  ! Test 1: n is zero
  call test_scenario(0, (1.0, 2.0), 1, 1)

  ! Test 2: ca is zero
  call test_scenario(5, (0.0, 0.0), 1, 1)

  ! Test 3: incx and incy are both 1
  call test_scenario(5, (1.0, 2.0), 1, 1)

  ! Test 4: incx and incy are not 1
  call test_scenario(5, (1.0, 2.0), 2, 3)

contains

  subroutine caxpy(n, ca, cx, incx, cy, incy)
    complex, intent(in) :: cx(*), ca
    complex, intent(inout) :: cy(*)
    integer, intent(in) :: n, incx, incy
    integer :: i, ix, iy

    if (n <= 0) return
    if (abs(real(ca)) + abs(aimag(ca)) == 0.0) return
    if (incx == 1 .and. incy == 1) then
      do i = 1, n
        cy(i) = cy(i) + ca * cx(i)
      end do
    else
      ix = 1
      iy = 1
      if (incx < 0) ix = (-n + 1) * incx + 1
      if (incy < 0) iy = (-n + 1) * incy + 1
      do i = 1, n
        cy(iy) = cy(iy) + ca * cx(ix)
        ix = ix + incx
        iy = iy + incy
      end do
    endif
  end subroutine caxpy

  subroutine test_scenario(n, ca, incx, incy)
    complex :: ca
    integer :: n, incx, incy, i
    complex, allocatable :: cx(:), cy(:)

    if (n > 0) then
      allocate(cx(n), cy(n))
    else
      allocate(cx(1), cy(1)) ! Allocate at least one element to avoid errors
    end if

    ! Initialize vectors
    do i = 1, n
      cx(i) = cmplx(i, -i) ! Use cmplx for complex numbers initialization
      cy(i) = cmplx(n-i, i-n)
    end do

    ! Call the caxpy subroutine
    call caxpy(n, ca, cx, incx, cy, incy)

    ! Output the result for verification
    print *, "Results for n=", n, ", ca=", ca, ", incx=", incx, ", incy=", incy
    do i = 1, n
      print *, "cy(", i, ") = ", cy(i)
    end do

    ! Clean up
    deallocate(cx, cy)
  end subroutine test_scenario

end program test_caxpy