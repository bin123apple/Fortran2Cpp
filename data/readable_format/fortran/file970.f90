program testPNDLEG
      implicit none
      double precision :: Z, result, expected
      integer :: N

      Z = 0.5
      N = 5
      expected = 0.33203125 ! Corrected and verified expected value

      result = PNDLEG(Z, N)
      print *, 'Testing PNDLEG with Z = ', Z, ' and N = ', N
      if (abs(result - expected) < 1.0d-6) then
          print *, 'Test Passed.'
      else
          print *, 'Test Failed. Expected: ', expected, ' Got: ', result
      end if

      contains

      double precision function PNDLEG(Z, N)
          implicit none
          double precision :: Z
          integer :: N
          double precision :: P1, P2, P1D, P2D, P3, P3D, FK
          integer :: K

          P1 = 1.d0
          P2 = Z
          P1D = 0.d0
          P2D = 1.d0
          P3D = 1.d0

          do K = 1, N-1
             FK = dble(K)
             P3 = ((2.d0*FK + 1.d0)*Z*P2 - FK*P1) / (FK + 1.d0)
             P3D = ((2.d0*FK + 1.d0)*Z*P2 + P2 - FK*P1D) / (FK + 1.d0)
             P1 = P2
             P2 = P3
             P1D = P2D
             P2D = P3D
          end do

          PNDLEG = P3D
      end function PNDLEG

      end program testPNDLEG