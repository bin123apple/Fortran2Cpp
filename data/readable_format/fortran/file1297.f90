program omp_do_test
  use omp_lib  ! For OpenMP functions
  implicit none
  integer :: i, j, count
  integer :: num_threads

  count = 0
  num_threads = 0

  ! Enable parallel region
  !$omp parallel private(i, j) reduction(+:count)
  !$omp master
  num_threads = omp_get_num_threads()
  !$omp end master
  !$omp do collapse(2)
  do i = 1, 10
    do j = 1, 10
      if (i >= 5) then  ! Adjusted condition to avoid using CYCLE
        count = count + 1
      end if
    end do
  end do
  !$omp end do
  !$omp end parallel

  print *, "Expected count: 60, Actual count:", count
  print *, "Number of threads used:", num_threads

end program omp_do_test