! Combined file with hcrit subroutine and test program
program test_hcrit
  implicit none
  double precision :: xflow, rho, b, theta, dg, sqrts0, hk

  ! Test case 1
  xflow = 1.0d0
  rho = 1.0d0
  b = 1.0d0
  theta = 0.1d0
  dg = 1.0d0
  sqrts0 = 1.0d0
  
  ! Call the hcrit subroutine
  call hcrit(xflow, rho, b, theta, dg, sqrts0, hk)
  
  ! Print the result
  print *, "Test 1: hk =", hk

contains

  ! Here is the hcrit subroutine defined within the same file
  subroutine hcrit(xflow, rho, b, theta, dg, sqrts0, hk)
    implicit none
    ! Declare variables
    double precision, intent(in) :: xflow, rho, b, theta, dg, sqrts0
    double precision, intent(out) :: hk
    double precision :: tth, c1, xflow2, A, dBBdh, dAdh, BB, dhk

    ! Compute initial hk
    hk = (xflow / (rho * b))**2 / (dg * sqrts0)
    hk = hk**(1.d0 / 3.d0)

    ! Early exit for small theta
    if (abs(theta) < 1.d-10) return

    tth = tan(theta)
    c1 = rho * rho * dg * sqrts0
    xflow2 = xflow * xflow

    ! Iteration loop
    do
      A = hk * (b + hk * tth)
      dBBdh = 2.d0 * tth
      dAdh = b + hk * dBBdh
      BB = dAdh
      dhk = (xflow2 * BB - c1 * A**3) / (xflow2 * dBBdh - 3.d0 * c1 * A * A * dAdh)
      
      if (abs(dhk) / hk < 1.d-3) exit
      
      hk = hk - dhk
    end do
  end subroutine hcrit

end program test_hcrit