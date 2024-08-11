program test_fitting
  implicit none

  ! Declare variables and arrays directly in the program
  integer, pointer :: np2
  real, dimension(:), pointer :: xp2, yp2, ep2, th2, xpos2, ypos2

  ! Example of using these variables
  allocate(np2)
  np2 = 3
  allocate(xp2(3), yp2(3), ep2(3), th2(3), xpos2(3), ypos2(3))

  xp2 = [1.0, 2.0, 3.0]
  yp2 = [2.0, 4.0, 6.0]
  ep2 = [0.1, 0.2, 0.3]
  th2 = [0.0, 0.5, 1.0]
  xpos2 = [10.0, 20.0, 30.0]
  ypos2 = [20.0, 40.0, 60.0]

  ! Call the example subroutine
  call process_data(xp2, yp2, np2)

  ! Clean up
  deallocate(np2, xp2, yp2, ep2, th2, xpos2, ypos2)

contains

  subroutine process_data(x_data, y_data, num_points)
    integer, intent(in) :: num_points
    real, dimension(:), intent(in) :: x_data, y_data

    integer :: i
    print *, 'Processing data...'
    do i = 1, num_points
      print *, 'X:', x_data(i), 'Y:', y_data(i)
    end do
  end subroutine process_data

end program test_fitting