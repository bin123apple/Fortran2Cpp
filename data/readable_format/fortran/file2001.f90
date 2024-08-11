program main
  implicit none

  ! Define the types directly within the same file
  type :: evtlist_type
     real, allocatable, dimension(:) :: p1
     real, allocatable, dimension(:) :: p2
     real, allocatable, dimension(:) :: p3
     real, allocatable, dimension(:) :: p4
  end type evtlist_type

  type :: evtlistlist_type
     type(evtlist_type) :: evtlist(1:1)
  end type evtlistlist_type

  type(evtlist_type), dimension(10) :: a
  integer :: i

  ! Example usage of the type
  allocate(a(1)%p1(10), a(1)%p2(10), a(1)%p3(10), a(1)%p4(10))

  ! Assign values to demonstrate functionality
  do i = 1, 10
     a(1)%p1(i) = i
     a(1)%p2(i) = i * 2.0
     a(1)%p3(i) = i * 3.0
     a(1)%p4(i) = i * 4.0
  end do

  ! Insert a simple test or print statement to verify the values
  print *, "p1 values: ", a(1)%p1
  print *, "p2 values: ", a(1)%p2
  print *, "p3 values: ", a(1)%p3
  print *, "p4 values: ", a(1)%p4

  ! Deallocate arrays
  deallocate(a(1)%p1, a(1)%p2, a(1)%p3, a(1)%p4)

end program main