PROGRAM ex1_test
  use omp_lib
  IMPLICIT NONE

  integer :: num_steps = 100000
  real :: step
  real :: pi, x
  real :: summ
  integer :: i
  real, parameter :: known_pi = 3.14159
  real :: error_margin = 0.001
  real :: error

  step = 1.0/num_steps

  summ = 0.0
  !$OMP PARALLEL DO REDUCTION(+:summ)
  do i=0, num_steps
    x = (i+0.5)*step
    summ = summ + 4.0/(1.0+ x*x)
  end do
  !$OMP END PARALLEL DO

  pi = summ * step
  
  error = abs(known_pi - pi)
  
  IF (error <= error_margin) THEN
    write(*,*) 'Test Passed: pi is ', pi
  ELSE
    write(*,*) 'Test Failed: pi is ', pi, ' with error ', error
  END IF

END PROGRAM ex1_test