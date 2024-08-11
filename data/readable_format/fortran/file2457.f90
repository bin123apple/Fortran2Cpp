module timing_module
  implicit none
contains
  function MPI_wtime()
    implicit none
    double precision :: MPI_wtime
    integer :: time, rate, dummy

    call system_clock( time, rate, dummy )
    MPI_wtime = dble(time) / dble(rate)
  end function MPI_wtime
end module timing_module

program test_timing_module
  use timing_module
  implicit none

  double precision :: start_time, end_time

  ! Get the current time
  start_time = MPI_wtime()
  print *, "Start time: ", start_time

  ! Perform some dummy work to introduce a delay
  call sleep(1)

  ! Get the current time again
  end_time = MPI_wtime()
  print *, "End time: ", end_time

  ! Calculate and print the elapsed time
  print *, "Elapsed time: ", end_time - start_time, " seconds"
end program test_timing_module