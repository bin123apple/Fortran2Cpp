program test_per_labsim2
      implicit none
      double precision, allocatable :: a(:,:), b(:), x(:)
      integer :: n, itmax, i, j, it, ifl
      double precision :: eps, ast, xst

      n = 2
      itmax = 100
      eps = 1.0e-6
      allocate(a(n,n), b(n), x(n))

      ! Define a simple system: x + y = 3, 2x + y = 4
      a(1,1) = 1.0
      a(1,2) = 1.0
      a(2,1) = 2.0
      a(2,2) = 1.0
      b(1) = 3.0
      b(2) = 4.0

      call per_labsim2(n, a, b, x, eps, itmax)

      print *, "Solution x:", x

      deallocate(a, b, x)

contains

      subroutine per_labsim2(n, a, b, x, eps, itmax)
            implicit none
            integer :: n, itmax, i, j, it, ifl
            double precision, dimension(n,n) :: a
            double precision, dimension(n) :: b, x
            double precision :: eps, ast, xst

            do i=1,n
               x(i)=0.0
               ast=a(i,i)
               b(i)=b(i)/ast

               do j=1,n
                  if (j /= i) then
                     a(i,j)=a(i,j)/ast
                  endif
               end do
            end do

            do it=1,itmax
               ifl=1

               do i=1,n
                  xst=x(i)
                  x(i)=b(i)

                  do j=1,n
                     if (i /= j) then
                        x(i)=x(i)-a(i,j)*x(j)
                     endif
                  end do

                  if(abs(xst-x(i)) > eps) then
                     ifl=0
                  endif
               end do

               if(ifl==1) exit
            end do

            if (ifl /= 1) then
               print *, 'No convergence after', itmax, 'iterations.'
            endif

      end subroutine per_labsim2

end program test_per_labsim2