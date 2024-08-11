program main
  implicit none

  integer :: resc(3), tmp(3)
  integer :: me, boss, i
  integer :: num_images, image_index

  ! Simulating the this_image() and num_images() functionality
  me = 1
  boss = 3
  num_images = 4  ! Assuming a total of 4 processes for this simulation

  ! Initialize resc based on the condition
  if (me == boss) then
     resc = 0
  else
     resc = -huge(0)
  endif

  ! Simulate the critical section and operations for both boss and non-boss "images"
  ! Note: This is a sequential simulation and does not reflect true parallel execution
  if (me /= boss) then
     ! Simulate receiving the array from the boss and modifying it
     do i = 1, 100
        tmp = resc
        tmp(1) = tmp(1) + 1
        tmp(2) = tmp(2) + 1
        ! Simulate sending the modified array back to the boss
        resc = tmp
     end do
  else
     ! Simulate the boss process updating its own array based on received updates
     do i = 1, 100 * (num_images - 1)
        resc(1) = resc(1) - 1
        resc(3) = resc(3) + 1
     end do
  endif

  ! Printing the results for this simulation
  write(*,*) "Image ", me, ":", resc

end program main